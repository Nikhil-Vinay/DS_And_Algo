/* Reverse the bits of a number */
/* Print the bit pattern of a number */
/* Left/Right Rotate of bit pattern of a number can also be solved by this way,
 * We can apply string rotation method also . :-)
 * But we have a beautiful weapo as shift operator with bit manupulation dealing.
 * So, best way to rotate bits is done by shift operator
 */
 
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void PrintBitPattern(int num)
{
   string str = "";
   size_t size = sizeof(num) * 8;
   for(size_t i = 0; i < size; i++) {
      if(num & (1 << i)) {
        str.insert(0, "1");
      } else {
        str.insert(0, "0");
      }
   }
   cout<<str<<endl;
}

void ReverseBit(int &num)
{
  size_t size = sizeof(num) * 8;
  int i = 0;
  int j = size-1;
  
  while(i < j) {
     // swap the bits at i and j
     int ith_bit = num & (1<<i);
     int jth_bit = num & (1<<j);
     // set jth bit
     if((ith_bit && !jth_bit) || (!ith_bit && jth_bit)) { // both are not same, flip both the bits
        num ^= (1 << i);
        num ^= (1 << j);
     }

     i++;
     j--;       
  } 
}

int main()
{
   int num;
   cout<<"Enter the number: "<<endl;
   cin>>num;
   cout<<"Enetered number's bit pattern is: "<<endl;
   PrintBitPattern(num);
   ReverseBit(num);
   PrintBitPattern(num);
   return 0;
}
