/***** Find length of longest common substring for two given strings ***********/
/* Example: string1: "abcde"
 *          string2: "acdb"
 *          Longest Common SUbstring : "cd"
 *          Note: substring is always sequencial characters
 */

/* Time complexity = O(m*n) */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int LCS(string str1, string str2)
{
   int m = str1.length();  
   int n = str2.length();
  
   int** dp = new int*[m+1];
   for(int i = 0; i <= m; i++) {
      dp[i] = new int[n+1];
   }

   // Inititalize
   for(int i = 0; i <= m; i++) {
      for(int j = 0; j <= n; j++) {
         dp[i][j] = 0;
      }
   }

   int count = 0;

   // Populate dp array
   for(int i = 1; i <= m; i++) {
      for(int j = 1; j <= n; j++) {
         if(str1[i-1] == str2[j-1]) {
            dp[i][j] = dp[i-1][j-1] + 1;
            count = max(count, dp[i][j]); 
         } else {
           dp[i][j] = 0;
           count = max(count, dp[i][j]);
         }
      }
   }
   // deallocate dp array

   return count;
}

int main()
{
  string str1, str2;
  cout<<"Enter the string-1"<<endl;
  getline(cin, str1);      // cin>>str1 skips whitespaces    
  cout<<"Enter the string-2"<<endl;
  getline(cin, str2);
  cout<<"Given two strings are: "<<str1<<" and "<<str2<<endl;

  int n = LCS(str1, str2);
  cout<<"Length of longest common substring is: "<<n<<endl;
  return 0;
}          
