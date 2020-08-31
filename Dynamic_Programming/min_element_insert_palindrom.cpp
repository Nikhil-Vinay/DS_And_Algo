/**** Find minimum character count to insert in a string to make a string palindrome ***********/

/* Example: If we have string "ABB" then after inserting 'A', string will become palindrome.
 * So, amswer = 1.
 * Example: If we have string "ABC".
 * So, amswer = 2.
 * Note: We can make insertion in diffrenet ways in this case to make palindrome.
 * ABCBA, ACBCA, CBABC  etc..
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/* Recursive solution */
int MinInsertionCount(string str, int start, int end, int** dp)
{
   if (start == end) {
      return 0;
   }
  
   if (start > end) {
      return 0;
   }

   if(dp[start][end]) {
      return dp[start][end];
   }

   int sol = 0;
   if(str[start] == str[end]) {
      sol = MinInsertionCount(str, start+1, end-1, dp);
   } else {
      sol = 1 + min(MinInsertionCount(str, start+1, end, dp),
                 MinInsertionCount(str, start, end-1, dp));
   }
 
   dp[start][end] = sol;
   return sol; 
}

int main()
{
   string str;
   cout<<"Please enter the string"<<endl; 
   // cin >> str; It is not safe because it truncates at white space 
   getline (cin, str);

   int** dp = new int* [str.length()];
   for(int i = 0; i < str.length(); i++) {
      dp[i] = new int [str.length()];
   }

   for(int i = 0; i < str.length(); i++) {
      for(int j = 0; j < str.length(); j++) {
          dp[i][j] = 0;
      }
   }

   int len = MinInsertionCount(str, 0, str.length()-1, dp);
   cout<<"Min char to insert to make string palindrome: "<<len<<endl;
}
