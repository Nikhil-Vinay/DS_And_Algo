/*********** Length Of Longest common subsequence of two strings **********************/
/** Note: Difference between longest common subsequence and longest common substring.
 * string1 = "abcdaf"
 * string2 = "bacdf"
 *
 * Longest common subsequence os str1 and str2 = "bcdf"
 * Longest common substring of str1 and str2 = "cd"  [substring is always contiguous char]
 *
 * Note: We can solve it with top-down and bottom-up approach 
 * In bottom up approach, we populate the table to find out length of longest common subsequence of two strings
 * then we can find out the longest common subsequence with help of table. Same can be applied for top-down
 * approach also. *
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int LCS(string str1, string str2, int len1, int len2, int** dp)
{
  if(len1 == 0 || len2 == 0) {
    return 0;
  }

  if(dp[len1][len2]) {
     return dp[len1][len2];
  }

  if(str1[len1-1] == str2[len2-1]) {
     dp[len1][len2] = 1 + LCS(str1, str2, len1-1, len2-1, dp);
     return dp[len1][len2];
  }

  int ans1 = LCS(str1, str2, len1-1, len2, dp);
  int ans2 = LCS(str1, str2, len1, len2-1, dp);

  dp[len1][len2] = max(ans1, ans2);
  return dp[len1][len2];
}

int bottomUp(string str1, string str2, int len1, int len2, int** dp) 
{

  // len1 is row and len2 is column
  // draw 2-d table, place strin1 at row and string2 at column and populate by dry run character by character
  // if string2 is null then first column will be zero
  for(int i = 0; i <= len1; i++) {
     dp[i][0] = 0;
  } 

  // if string1 is null then first row will bw zero
  for(int j = 0; j <= len2; j++) {
     dp[0][j] = 0;
  }

  for(int i = 1; i <= len1; i++) {
     for(int j = 1; j <= len2; j++) {
        if(str1[i] == str2[j]) {
          dp[i][j] = dp[i-1][j-1] + 1;
        } else {
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
     }
  }
  return dp[len1][len2]; 
}

int main()
{
  string str1("abcdaf");
  string str2("bacdf");

  int **dp = new int*[str1.length()+1];
  for(int i = 0; i <= str1.length(); i++) {
     dp[i] = new int[str2.length()+1];
  }

  //cout<<"Length of longest common subsequence: "<<LCS(str1, str2, str1.length(), str2.length(), dp)<<endl;
  cout<<"Length of longest common subsequence: "<<bottomUp(str1, str2, str1.length(), str2.length(), dp)<<endl;
  return 0;
}
