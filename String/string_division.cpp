/* There is a given string str1 and another small string str2. We need to find if str1 is divisible by str2.
 * 
 * Divisible means str1 can be formed by one or more number of serial concatenation of str1.
 * Example: str1: "abcdabcd", str2: "abcd".
 *          str1 can be formed by two serial concatenation of str2 so str1 is divisible by str2.
 *
 * Second thing is, if str1 is divisible by str2 then we need to find the smallest divisor string which can divide
 * str1 and str2.
 * Exmaple: str1: "abababab", str2: "abab"
 *          str1 is divisible by str2.
 *          But smallest devisor string is: "ab" which devides str1 and str2.
 *
 * If str2 is not divisible by str2 then return -1.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool IsStringDivisible(string str1, string str2)
{
   int len1 = str1.length();
   int len2 = str2.length();

   if(len1 % len2 != 0) {
     return false;
   }

   int i = 0;
   int j = 0;
   while(i < len1) {
      if(j == len2) {
         j = 0;
      }
      if(str1[i] != str2[j]) {
         break;
      }
      i++;
      j++;
   }

   if(i != len1 || j != len2){
      return false;
   }

   return true;

}

int main()
{
   string str1, str2;
   cout<<"Enter string1: "<<endl;
   cin>>str1;
   cout<<"Enter string2: "<<endl;
   cin>>str2;

   if(!IsStringDivisible(str1, str2)) {
      cout << "Not divisible" <<endl;      
   } else {
   
     int len2 = str2.length();  
     // now str1 is divisible by str2
     // we need to find the smallest string which can devide str2
     int start = 0;
     int end = len2;
     int len = end - start;
     while(len > 1) {
        cout<<"start"<<endl;
        string tmpstr = str2.substr(0, (int)(len/2));
        cout<<"end: "<<tmpstr<<endl;
        if(!IsStringDivisible(str2, tmpstr)){
           break;
        }
        len = len/2;  
     }
     cout<<"Min divisor substring length is: "<<len<<endl;  
   }
   return 0;
}
