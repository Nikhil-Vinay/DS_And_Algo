/********* 0 - 1 Knapsack problem *****************/
/* There is a thief which goes to a shop with a sack of weight capacity w
 * Shop has different items with different price and different weight
 * We need to find what the maximum price items thief can collect.
 *
 * Constraint: Every item is only one in quantity
 *
 * Note: greedy will not work here (don't pick the costliest item)
 *
 * Based on inclusion/exclusion theory
 *
 * It is called 0-1 knapsack because either you can take one item or leave item, you cant take partial item
 *
 * Note: Here every item is only one in quantity so that we decrease the array size in both the case - includig 
 * and excluding. If all items will be ininite in quantity then it will be become vey similar to max num ways of
 * coin changing prob becuse here also repetitive solution not allowed means collecting items { x, x, y } and
 * { y, y, x } are not different. In this case we don't need to decrease the array in case of inclusion, only 
 * need to decrease the array in case of exclusion. Base condtion is alos modified */

#include<iostream>
#include<bits/stdc++.h>
#define DEBUG 1

using namespace std;

int knapsack(int wts[], int prices[], int n, int w, int** dp)  // w is changing and n is changing so 2-D dp 
{
   if(n == 0 || w == 0) {
      return 0;
   }

   if(dp[n][w]) {
     return dp[n][w];
   }
 
   int inc = 0, exc = 0;

   // including current item
   if(wts[n-1] <= w) {
     inc = prices[n-1] + knapsack(wts, prices, n-1, w-wts[n-1], dp);
   }

   // excluding the current item

   exc = 0 + knapsack(wts, prices, n-1, w, dp);

   dp[n][w] = max(inc, exc);
   return dp[n][w];
   
}

int bottomUp(int wts[], int prices[], int n, int w)
{
  int dp[100][100];
  for(int item = 0; item <= n; item++) {
     for(int wt = 0; wt <=w ; wt++) {
       if(item == 0 || wt == 0) {  // first row and first column will always be zero
         dp[0][0] = 0;
       } else {
         int inc =0, exc = 0;
         // inc
         if(wts[item-1] <= wt) {
            inc = prices[item-1] + dp[item-1][wt-wts[item-1]];
         } 

         //exc
         exc = dp[item-1][wt];  // we have bag capacity of wt and number of item is item. For excluding
                                // pick till previous number of items with same weight 
         dp[item][wt] = max(inc, exc); 
       }      
     }
   }
#if DEBUG
   // print table
   cout<<" Table is: "<<endl;
   for(int i = 0; i <= n; i++) {
      for(int j = 0; j <= w; j++) {
         cout<<dp[i][j]<<"  ";
      }
      cout<<endl;
   }
#endif
   return dp[n][w];
}


int main()
{
  int wts[] = { 2, 7, 3, 4 };
  int prices[] = { 5, 20, 20, 10 };
  int n = 4;
  int w = 11;

  // create a dp table
  int** dp = new int*[n+1];
  for(int i = 0; i <= n; i++) {
     dp[i] = new int[w+1];
  }

  //int maxProfit = knapsack(wts, prices, n, w, dp);
  int maxProfit = bottomUp(wts, prices, n, w);
  cout<<maxProfit<<endl;
  return 0;
}
