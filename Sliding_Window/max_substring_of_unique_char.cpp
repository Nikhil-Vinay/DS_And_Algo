/** Given a string of all small letters, find max length of substring having unique characters */
/* Example: string - "abacfghcfh"
 *          max length of substr of unique char = 6 ("bacfgh")
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int MaxLen(string str)
{
   if(str.length() == 1) {
      return 1;
   }

   int maxlen = 0;
   int hash[26] = {0};

   int i = 0, j= 0;
   while(i < str.length()-1) {
     
      if(hash[str[i]-'a'] == 0) {
         hash[str[i]-'a']++;
         maxlen = max(maxlen, i-j+1);
         i++;
      } else {
         bool removed = false;
         while(j <= i && !removed) {
           hash[str[j]-'a']--;
           if(str[j] == str[i]) {
              removed = true;
           }
           j++;
        }
     }
   }
   return maxlen;
}

int main()
{
   string str = "abacfghcfh";

   cout<<"Max substring length: "<<MaxLen(str)<<endl;
   return 0;
}          
