/**** FInd minimum character count deletion to make a string palindrome ***********/

/* Example: If we have string "ABBCDDBBA" then after deleting 'C', string will become palindrome.
 * So, amswer = 1.
 */

#include<iostream>
#include<bits/stdc++.h>
#define DEBUG 0

using namespace std;

int MinCharDeletion(string str) 
{
  int n = str.length();
  // dp table
  int** table = new int*[n];
  for(int i = 0; i < n; i++) {
     table[i] = new int[n];
  }

  /* We will find max palindrome length in the given string then num of char deletion will be - (string length -
   * max palindrome length)
   * table[i][j] represents substring from index i to j.
   * This way we will traverse to all substrings of the string - all substrings of length 1, all substrings of
   * length 2, ..... all substrings of length n
   * Only benefit of dp solution is we are getting rid of overlapping subproblems. Example for finding solution
   * of substring x to y, we will use stored solution of substring x+1 to y-1.
   * We know single character at every index of string is a palindrome, so table[i][j] = 1 for i = j;
   */

   for(int i = 0; i < n; i++) {
      table[i][i] = 1;
   }

   /* fill up rest of the table with below concept
    *
    * table[i][j] =  table[i+1][j-1] + 2, if (str[i] = str[j])
    *             =  max(table[i+1][j], table[i][j-1]), if (str[i] != str[j])
    */

    // We have already filled diagonal of the table and we need to know the value of table[0][n-1] for full str
    // We need to fill rest all diagonals on top of main diagonal.
    // Draw any 3x3 table then below for loop implementation will be clear
    // Number of rest diagonals to fill up = n-1

    for(int diag = 1; diag <= n-1; diag++) {  // iterate for number of diagonal
        // every diagonal has (n-diag) cells
        for(int cell = 0; cell < (n-diag); cell++) {
           int x = cell; 
           int y = x + diag;
           if(str[x] == str[y]) {
              table[x][y] = table[x+1][y-1] + 2;
           } else {
              table[x][y] = max(table[x+1][y], table[x][y-1]);
           }
       }
    }

#if DEBUG
    for(int i = 0; i < n; i++) {
       for(int j = 0; j < n; j++) {
          cout<<table[i][j]<<" ";
       }
       cout<<endl;
    }
#endif
 
    return n - table[0][n-1];
}

/* Recursive solution */
int MaxPalindromicSubsequenceLength(string str, int start, int end, int** dp)
{
   if (start == end) {
      return 1;
   }
  
   if (start > end) {
      return 0;
   }

   if(dp[start][end]) {
      return dp[start][end];
   }

   int sol = 0;
   if(str[start] == str[end]) {
      sol = 2 + MaxPalindromicSubsequenceLength(str, start+1, end-1, dp);
   } else {
      sol = max(MaxPalindromicSubsequenceLength(str, start+1, end, dp),
                 MaxPalindromicSubsequenceLength(str, start, end-1, dp));
   }
 
   dp[start][end] = sol;
   return sol; 
}

int main()
{
  
   string str("ABBCDDBBA");
   //string str("ABCDBA");
   // Iterative method solution
   cout<<"Min char to delete to make string palindrome: "<<MinCharDeletion(str)<<endl;
   // Recursive method solution with top down approach
   int** dp = new int* [str.length()];
   for(int i = 0; i < str.length(); i++) {
      dp[i] = new int [str.length()];
   }

   for(int i = 0; i < str.length(); i++) {
      for(int j = 0; j < str.length(); j++) {
          dp[i][j] = 0;
      }
   }

   int len = MaxPalindromicSubsequenceLength(str, 0, str.length()-1, dp);
   cout<<"Min char to delete to make string palindrome: "<<str.length()-len<<endl;
}
