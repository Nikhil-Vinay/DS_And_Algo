/*** There is an given array which has price of wine bottles.
 *   We have to maximize the profit by selling the wine bottles.
 *   Constraints are following:
 *   1. Every year only one wine bottle is sold either the leftmost bottle or the rightmost bottle.
 *   2. Every year wine bottle price will be multiplied by number of years.
 *
 *   Example: p[5] = {2, 3, 5, 1,4 }
 *   Greedy approach will select every time the least price from end.
 *   Greedy solution: 2*1 + 3*2 + 4*3 + 1*4 + 5*5 = 49
 *
 *   Other solution: 2*1 + 4*2 + 1*3 + 3*4 + 5*5 = 50
 *
 *   So. we will solve it recursively with use of dp.
 *   
 *   i = left most  index.
 *   j = right most index
 *   y = year of selling
 *   f(i, j, y) = max ( y*arr[i] + f(i+1, j, y+1), y*arr[j] + f(i, j-1, y+1) )
 *
 *   It seems it is 3D dp problem but it is actually 2D dp problem as year(y) can be calculated in each iteration
 *   as: y = N - (j-i)   // N is total number of elements in array.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int MaxProfit(int* arr, int len, int i, int j, int** dp)
{
   // base condition
   if(j < i) {
      return 0;
   }

   if(dp[i][j] != -1){
     return dp[i][j];
   }

   int year_of_selling = len - (j - i);
   int profit = max( year_of_selling*arr[i] + MaxProfit(arr, len, i+1, j, dp),
                     year_of_selling*arr[j] + MaxProfit(arr, len, i, j-1, dp));

   dp[i][j] = profit;
   return profit;
}

int main()
{
  int arr[5] = { 2, 3, 5, 1, 4};
  int len = sizeof(arr)/ sizeof(arr[0]);
  cout<<"len is: "<<len<<endl;

  // create dp table
  int** dp = new int*[len];
  for(int i = 0; i < len; i++) {
     dp[i] = new int[len];
  }

  for(int i = 0; i < len; i++) {
     for(int j = 0; j < len; j++) {
        dp[i][j] = -1;
     }
  }

  int profit = MaxProfit(arr, len, 0, len-1, dp);

  cout<<"Max profit of wine seeling is: "<<profit<<endl;

  return 0;
}
