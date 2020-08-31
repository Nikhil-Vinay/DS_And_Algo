/************** Encode a string in place **************************/

/* There is a string in continuous repeating character format,  we need to encode the string in given fashion:
 * Original String(Input) = "AABDDDCCCC"
 * Encoded String(output) = 2AB3D4C   
 * Note: 1. if same character is occuring continuously multiple times then we need to encode it as 'count+char'
 *       2. If a character is occuring once in continuity then don't write 1+char because character occured one
 *          time and we write two character(1+char) then unnecessarily we are using one extra char for count 1.
 *          This violates the rule of compression.
 *
 * Important Constraint: We have to compress the string in place. It means we can't use another string to store
 * encoded(compressed) string. If we are allowed to use another string for encode string then prob will become
 * simple.
 */

/* Note: The below solution is only for encoded string, we can decode easily with same concept as encoding.
 *        For decoding we can't do it inplace(in same string). We need another string to store decoded string
 *        because write_idx will go ahead of read_idx in case of in place decoding and it will loose the data.
 */        

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<typename T, size_t N>
void EncodeString(T (&str)[N])
{
  if (str[0] == '\0') {   // check for empty string
     return;
  }
 
  int read_idx = 0, write_idx = 0;
  char ch;
  int count = 0;
  while(str[read_idx] != '\0') {   // read_idx >= write_idx
    if(read_idx == 0) {            // for first character
      ch = str[read_idx++];
      count++;
    } else {
      if(str[read_idx] == ch){    // if same character, continue reading with read_idx increment
        count++;
        read_idx++;
      } else {                     
        if(count == 1) {          // write for character at write index
          str[write_idx++] = ch;
        } else {                  // write for multiple character stream  
          str[write_idx++] = count + '0';
          str[write_idx++] = ch;
        }
        ch = str[read_idx++];
        count = 1;
      }
    }
  }
  // write last character stream which is pending because while control comes out with null character
  if(count == 1) {
    str[write_idx++] = ch;
  } else if(count > 1) {
    str[write_idx++] = count + '0';
    str[write_idx++] = ch;
  } 

  str[write_idx] = '\0';
}

int main()
{
  // char* ptr = "AABBBCDDDD"; // we will not use this pattern since it will go in read only memory. We can't
                               // write in place here. It will throw segmentation fault in case of inplace write
  char str[15];
  memset(str, 0, sizeof(str));
  strcpy(str, "AABBBCDDDD");   // we can use - string str("AABBBCDDDD") 

  cout<<"original string is : "<<str<<endl;
  EncodeString(str);
  cout<<"Encoded string is : "<<str<<endl;
//  DecodeString(str);
//  cout<<"Decoded String is: "<<endl;
}
