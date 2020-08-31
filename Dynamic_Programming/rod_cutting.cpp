/************* ROD CUTTING PROBLEM **************************************/
/* There a rod length is given as n and two arrays are given - one is length array and other is prices array.
 * Price array includes prices respective to length array. It means if length array ith index is Li and price
 * array ith index is Pi then Li length rod costs Pi in the market.
 *
 * We need to find out the maximum profit by cutting the rods in different pieces.
 *
 * Note: This problem is very similar to knapsack_0_1 problem with infinite number of items(we can cut same 
         length multiple times). In knapsack problem, we have weights and price associated (for length and price)
          and sack capacity (for rod length).
 *
 * It is also based on inclusion, exclusion method. We can include some rod length (for cutting) or exclude some
   rod length (for cutting). Repetition pattern is not considered - length { x, x, y } is similar to { y, x, x } 
 */

#include<iostream>
#include<bits/stdc++.h>
#define DEBUG 1

using namespace std;

int MaxProfit(int lengths[], int prices[], int n, int l, int** dp)  // w is changing and n is changing so 2-D dp 
{
   if(n == 0 || l == 0) {
      return 0;
   }   

   if(dp[n][l]) {
     return dp[n][l];
   }   
 
   int inc = 0, exc = 0;

   // including current length for cutting
   if(lengths[n-1] <= l) {
      inc = prices[n-1] + MaxProfit(lengths, prices, n, l-lengths[n-1], dp);  // in case of includion, we wont
   }                                                                          // decrease the array length bcoz
                                                                              // we can cut same length again
   // excluding the current length for cutting

   exc = 0 + MaxProfit(lengths, prices, n-1, l, dp);

   dp[n][l] = max(inc, exc);
   return dp[n][l];

}

int bottomUp(int lengths[], int prices[], int n, int l)
{
  // draw the 2-D table with total cutting length array as row and total lengths as columns, then it will become
  // clear.
  int dp[100][100];
  for(int i = 0; i <= n; i++) {
     for(int ln = 0; ln <= l; ln++) {
       if(i == 0 || ln == 0) {  // first row and first column will always be zero 
                                // 1. if total length of rod(colmn) is zero then whatever cutting lengths, 
                                // results will be zero
                                // 2. if cutting length array(row) has zero elements then whatever total rod 
                                // length, result will be zero
         dp[0][0] = 0;
       } else {
         int inc =0, exc = 0;

         //inc
         if(lengths[i-1] <= ln) {
            inc = prices[i-1] + dp[i][ln-lengths[i-1]];
         }

         //exc
         exc = dp[i-1][ln];  // For excluding
                             // pick till previous number of cutting lengths with same total length
         dp[i][ln] = max(inc, exc);
       }
     }
   }

#if DEBUG
   cout<<"Table is : "<<endl;
   for(int i = 0; i <= n; i++) {
      for(int j = 0; j <= l; j++) {
         cout<<dp[i][j]<<"  ";
      }
      cout<<endl;
   }
#endif
   return dp[n][l];
}

int main()
{
  int lengths[] = { 1, 2, 3, 4 };
  int prices[] = { 2, 5, 7, 8 };
  int n = 4;
  int l = 5;  // total rod length

  // create a dp table
  int** dp = new int*[n+1];
  for(int i = 0; i <= n; i++) {
     dp[i] = new int[l+1];
  }

  int maxProfit = MaxProfit(lengths, prices, n, l, dp);
  //int maxProfit = bottomUp(lengths, prices, n, l);
  cout<<maxProfit<<endl;
  return  0;
}
