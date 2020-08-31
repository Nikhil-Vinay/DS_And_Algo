/*** Find length of longest substring of a given string of digits, such that sum of digits in first half and
 * second half of the substring is same.
 *
 * Example: string is "142124", (1+4+2) = (1+2+4) // length is 6
 *          string is "9430723"  (4+3) = )0+7)    // length is 4
 *
 * Note: If you can't solve this, first look into dp prob - "min_element_delete_palindrom.cpp".
 *       All theoretical concept mentioned there is applicable here.
 *
 * Important: Wherever we need to look into all substrings of a string and we build solution of bigger substring
 *            from smaller substring, we apply this tabulation method of bottom-up DP.
 *
 */

#include<iostream>
#include<bits/stdc++.h>
#define DEBUG 0

using namespace std;

int LongestSubstring(string str)
{
   int max_sum = 0;
   int max_sum_length = 0;
   int n = str.length();
   // create dp table
   int** table = new int*[n];
   for(int i = 0; i < n; i++) {
      table[i] = new int[n];
   }

   // for single character substring, sum is character value
   for(int i = 0; i <n; i++) {
      table[i][i] = str[i] - '0';
   }

   // here, we have to find a substring whose both halves have equal sum so, we need to consider only even length
   // substrings.
   // We need to fill up total n-1 diagonals.
   
   for(int diag = 1; diag <= n-1; diag++) {
      // each diag will have (n-diag) cells
      for(int cell = 0; cell < (n-diag); cell++) {
         int x = cell;
         int y = x + diag;
         // x is start index of substr and y is end index of substr
         // we have to find solution for even length substr so, if (y-x+1)%2 == 0 then substr length is even
         // If substr length is even, we need to find the middle index
         table[x][y] = table[x+1][y-1] + (str[x]-'0') + (str[y]-'0');
         if((y-x+1)%2 == 0) {
            int mid = x + (y-x)/2;
            int first_half_sum = table[x][mid];
            int second_half_sum = table[mid+1][y];
            if((first_half_sum == second_half_sum) && ((first_half_sum + second_half_sum) > max_sum)) {
               max_sum = first_half_sum + second_half_sum;
               max_sum_length = y-x+1; 
            } 
         }
      }
   }
#if DEBUG
   // print table
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
         cout<<table[i][j]<<"  ";
      }
      cout<<endl;
   }
#endif

   return max_sum_length;
}

int main()
{
  string str("142124");
  //string str("9430723");
  cout<<"length of logest substring of eui half sum is: "<<LongestSubstring(str)<<endl;

  return 0;
}          
