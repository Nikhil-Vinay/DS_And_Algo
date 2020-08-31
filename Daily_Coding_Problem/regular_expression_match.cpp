/************** Implement a regular expression matching pattern (Facebook) ******************************/

/* Implement regular expression matching with the following special characters:
 *  . (period) which matches any single character
 *  * (asterisk) which matches zero or more of the preceding element.
 *
 * That is, implement a function that takes in a string and a valid regular expression and returns whether or 
 * not the string matches the regular expression.
 *
 * For example, given the regular expression "ra." and the string "ray", your function should return true. The 
 * same regular expression on the string "raymond" should return false.
 *
 * Given the regular expression ".*at" and the string "chat", your function should return true. The same regular
 * expression on the string "chats" should return false.
 */

#include<iostream>
#include<bits/stdc++.h>

#define MAX_STR_LEN 10
#define DEBUG 0

using namespace std;

int StringMatch(string str1, string str2, int length1, int length2, int index1, int index2, int** dp)
{
  if((length1 > 0 && length2 == 0) || (length2 > 0 && length1 == 0)) {
     
     return 0;
  }
  if(length1 == 0 && length2 == 0) {
    return 1;
  }

  // Note: index and length are dependent on each other, index is inxreasing then length is decreasing
  // So, here we consider two dimensional DP with length varying

  if(dp[length1][length2] != INT_MAX) {
     return dp[length1][length2];
  }
  // Note : str1 is original string, str2 can have wild card (. and *)
  if(str1[index1] == str2[index2]){
     dp[length1][length2] =  StringMatch(str1, str2, length1-1, length2-1, ++index1, ++index2, dp);
     return dp[length1][length2];
  }

  if(str2[index2] == '.') {
     dp[length1][length2] =  StringMatch(str1, str2, length1-1, length2-1, ++index1, ++index2, dp);
     return dp[length1][length2];
  }

  if(str2[index2] == '*'){
     // Note: there are two conditions below, a simple dry with tree diagram will explain better.

     // matching current character of str1 with * of str2 and reducing both staring size thinking of * is
     // matching with current character only
     int ans1 = StringMatch(str1, str2, length1-1, length2-1, ++index1, ++index2, dp);
     // * of str2 is replacing the current character of str1 but * could replace more than one char of str1 so
     // decreasing length of str1 but keeping same length of str2
     int ans2 = StringMatch(str1, str2, length1-1, length2, ++index1, index2, dp);

     dp[length1][length2] =  (ans1 || ans2);
     return dp[length1][length2];
   }

   return 0;
}

int bottomUp(string str1, string str2)
{
  int length1 = str1.length();
  int length2 = str2.length();

  int** dp = new int*[length1];
  for(int i = 0; i <= length1; i++) {
      dp[i] = new int[length2+1];
  }

  // fill table for base condition, if str1 and str2 are emptty
  dp[0][0] = 1;
  // if str1 is empty and str2 is not empty
  for(int j = 1; j <= length2; j++) {
    dp[0][j] = 0;
  }

  // if str2 is empty and str1 is not empty
  for(int i = 1; i <= length1; i++) {
     dp[i][0] = 0;
  }

  // fill rest of the table
  for(int i = 1; i <= length1; i++) {
     for(int j = 1; j <= length2; j++) {
        if(str1[i-1] == str2[j-1]){
           dp[i][j] = dp[i-1][j-1];
        } else if (str2[j-1] == '.') {
           dp[i][j] = dp[i-1][j-1];
        } else if (str2[j-1] == '*') {
           dp[i][j] = dp[i-1][j-1] || dp[i-1][j];
        }
     }
  }

#if DEBUG
  for(int i = 0; i <= length1; i++) {
     for(int j = 0; j <= length2; j++) {
         cout<<dp[i][j]<<" ";
     }
     cout<<endl;
  }
#endif

  return dp[length1][length2];
}

int main()
{
  //string str1("ray");
  //string str2("ra.");

  //string str1("raymond");
  //string str2("ra.");

  //string str1("chat");
  //string str2(".*at");

  string str1("chat");
  string str2("*at");

  // We need to have dp[str1.length()+1][str2.length()+1] // 1 extra for empty string condition
  // Here for simplicity we are making dp table as dp[MAX_STR_LEN][MAX_STR_LEN]
  int** dp = new int*[MAX_STR_LEN];
  for(int i = 0; i < MAX_STR_LEN; i++) {
     dp[i] = new int[MAX_STR_LEN];
  }
  
  for(int i = 0; i < MAX_STR_LEN; i++) {
     for(int j = 0; j < MAX_STR_LEN; j++) {
        dp[i][j] = INT_MAX;
     }
   }

  cout<<(StringMatch(str1, str2, str1.length(), str2.length(), 0, 0, dp)?"matching":"not matching") << endl;

  // test with bottom up
  cout<<(bottomUp(str1, str2)?"matching":"not matching")<<endl;

  return 0;
}
