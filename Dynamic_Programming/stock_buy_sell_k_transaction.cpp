/*************** Maximize Profit By Buying and Selling Stock with K transaction **************/

/* Note: suppose  n days stock price is given in array - price[0], price[1]........price[n]
 * Total transaction count = k
 *
 * MaxProfit at day [i] = Max{ No transaction is done at day i [max profit at day i-1 with same tansaction count]
 *                                           OR
 *                             max(for m in (0.....i-1) - profit making by buying at day k and selling at day i)
 *                             [profit by purchasing at m and selling at i + total profit at day i-1 with one 
 *                              less transaction]
 *                           }
 *
 *Time complexity = O(n*k) x O(n) [for inner for loop] ~ O(n^2k)
 */

/** Note: The below dp solution is very generic dp solution.
 * 1. single transaction can also be solved by this method. - 0(n^2) but it is not efficient. Better to go with
 * O(n) solution,
 * 2. Two transaction problem can also be solved by this way but better to go with o(n) solution.
 * 3. Instead of fixed k transaction, any number of transaction problem can also be solved by this method.
 */

#include<iostream>
#include<bits/stdc++.h>

#define DEBUG 1
using namespace std;

int GetMaxProfit(vector<int> &price, int k)
{
   int days_count = price.size();
   // create 2D dp table 
   // total transaction 0..k is considered as row and price as column
   int** dp = new int*[k+1];   // one extra for 0 transaction
   for(int i = 0; i <= k; i++) {
      dp[i] = new int[days_count + 1]; // one extrs for 0 days
   }

   for(int i = 0; i <= k; i++) {
     dp[i][0] = 0;
   }
 
   for(int j = 0; j <= days_count; j++) {
      dp[0][j] = 0;                    // total profit is 0 for 0 transaction
   } 

   for(int i = 1; i <= k; i++) {
      for(int j = 1; j <= days_count; j++) {
         // fill at day - i, transaction count - j
         // no transaction at day i profit
         int profit1 = dp[i][j-1];  // total profit till last day with same transaction count
         int profit2 = INT_MIN;
         for(int m = 1; m < j; m++) {
            int pf = price[j-1]-price[m-1] + dp[i-1][m-1];   
            profit2 = max(profit2, pf);
         }
         dp[i][j] = max(profit1, profit2); 
      }
   }
#if DEBUG
   for(int i = 0; i <= k; i++) {
      for(int j = 0; j <= days_count; j++) {
         cout<<dp[i][j]<<" ";
      }
      cout<<endl;
   }
#endif
   return dp[k][days_count]; 
}

int main()
{
   int arr[6] = { 1, 6, 3, 9, 5, 25 };
   vector<int> vct (arr, arr+6);
   int k = 3;  // total transaction count
   cout<<GetMaxProfit(vct, k)<<endl;   
   return 0;
}                    
