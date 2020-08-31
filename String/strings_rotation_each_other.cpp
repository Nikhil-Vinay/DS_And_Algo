/**** Two strings are given. Check if str2 is rotated version of str1 ******/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool StringRotated(string str1, string str2)
{
   string tmpstr = str1+str1;
   if(tmpstr.find(str2) == string::npos) {
      return false;
   }
   return true;
}

int main()
{
   // char str[100];  // for char array
   // cin.get(str, 100);
   string str1, str2;
   cout<<"Enter string-1: "<<endl;
   getline(cin, str1);
   cout<<"Enter string-2: "<<endl;
   getline(cin, str2);

   if (StringRotated(str1, str2)) {
      cout<<"string-2 is rotated version of string-1"<<endl;
   } else {
      cout<<"string-2 is not rotated version of string-1"<<endl;
   }
   
   return 0;
}
