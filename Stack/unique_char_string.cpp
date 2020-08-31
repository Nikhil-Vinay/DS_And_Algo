/* There is a given string of repeated characters, we need to return a string made by unique characters of string.
 * characters should be in same order but we need to return the lexicographically min ordered string.
 * Example: Given string: babc
 *          Possiblities: bac and abc
 *          Answer: abc.  // lexicographically min ordered.
 *
 * Note: all letters in string are: a-z.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Time complexity = O(n) because each character will be inserted once and removed once in stack
string UniqueString(string str)
{
   int lastIndex[26] = {0};
   bool hash[26] = {false};
   stack<char> st;

   // preprocessed array to get last occurence of all unique characters
   for(int i = 0; i < str.length(); i++) {
      lastIndex[str[i] - 'a'] = i;
   }

   for(int i = 0; i < str.length(); i++) {
      if(hash[str[i]-'a'] == false){
         // need to check if we have any character in stack greater than current character awhich comes later
         while(!st.empty()){
            char tmp = st.top();
            if(tmp > str[i] && lastIndex[tmp - 'a'] > i) {  // this character comes later also
               // remove this character from stack, it will be included later
               st.pop();
               hash[tmp - 'a'] = false;
            } else {
              break;
            }
         }
         st.push(str[i]);  // push current character in stack
         hash[str[i] - 'a'] = true;
      }
   }

   string retstr = "";
   while(!st.empty()){
      retstr += st.top();
      st.pop();
   }
   reverse(retstr.begin(), retstr.end());
   return retstr;
}

int main()
{
   string str = "dbabdcd";
   cout<<UniqueString(str)<<endl;
   return 0;
}          
