/************ Print Encoded Message *********************************/

/* Given the mapping a=1, b=2, ...z=26 and an encoded message, count the number of ways it can be decoded.
 * For example, message is - 111. It can be decoded as - "aaa", "ka", "ak".
 * So number os ways to decode - 3.
 * Note: message will be always decodable, 001 is not allowed.
 */

/* It's a beautiful example of recursion */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

char GetChar(int index) {
  switch(index) {
     case 1: return 'A'; break;
     case 2: return 'B'; break;
     case 3: return 'C'; break;
     case 4: return 'D'; break;
     case 5: return 'E'; break;
     case 6: return 'F'; break;
     case 7: return 'G'; break;
     case 8: return 'H'; break;
     case 9: return 'I'; break;
     case 10: return 'J'; break;
     case 11: return 'K'; break;
     case 12: return 'L'; break;
     case 13: return 'M'; break;
     case 14: return 'N'; break;
     case 15: return 'O'; break;
     case 16: return 'P'; break;
     case 17: return 'Q'; break;
     case 18: return 'R'; break;
     case 19: return 'S'; break;
     case 20: return 'T'; break;
     case 21: return 'U'; break;
     case 22: return 'V'; break;
     case 23: return 'W'; break;
     case 24: return 'X'; break;
     case 25: return 'Y'; break;
     case 26: return 'Z'; break;
     default: assert(0); break;
  }
}

void DecodeString(string instr, int index, string tempstr)
{
  if(index == instr.length()){
    cout<<tempstr<<endl;
    return;
  }
  
  if(index < instr.length()) {
    int i = instr.at(index) - '0';
    DecodeString(instr, index+1, tempstr + GetChar(i));
  }

  if((index+1) < instr.length()) {
    int i = ((instr.at(index) - '0')*10 + (instr.at(index+1) - '0'));
    DecodeString(instr, index+2, tempstr + GetChar(i));
  }
  
  return; 
}

int main()
{
  string str("");
  string tempstr("");
  cout<<"Eneter the message to decode: "<<endl;
  cin>>str;

  cout<<"Decoded string are: "<<endl;
  DecodeString(str, 0, tempstr);
  return 0;
}


