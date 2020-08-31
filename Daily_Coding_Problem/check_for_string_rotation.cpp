/* Given two strings A and B, return whether or not A can be shifted some number of times to get B.
 *
 * For example, if A is abcde and B is cdeab, return true. If A is abc and B is acb, return false.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool CheckForStringRotation(string str1, string str2)
{
   if(str1.length() != str2.length()) {
     return false;
   }

   string tmpstr = str1 + str2;
   if(tmpstr.find(str1) == string::npos) {
      return false;
   }
 
   return true;
}

int main()
{
   string str1 = "abcde";
   string str2 = "cdeab";
   if(CheckForStringRotation(str1, str2)) {
     cout<<"strings are formed by rotation"<<endl;
   } else {
     cout<<"strings are not formed by rotation"<<endl;
   }
   return 0;
}
