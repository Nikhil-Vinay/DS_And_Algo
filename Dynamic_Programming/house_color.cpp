/* This problem was asked by Facebook.

A builder is looking to build a row of N houses that can be of K different colors. He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.

Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color, return the minimum cost which achieves this goal.

*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define COLOR_COUNT 3
#define HOUSE_COUNT 4

// Time complexity = O(house_count * color_count * color_count)
// house_count * color_count by dp state dp[house_count][color_count]
// another color_count by inner for loop

int MinCost(int color_cost[][HOUSE_COUNT], int house_idx, int color_idx, int** dp)// color_idx is row and house_i
                                                                                  // dx is columns
{
   // base condition
   if (house_idx == 0) {
      dp[color_idx][house_idx] = color_cost[color_idx][house_idx];
      return color_cost[color_idx][house_idx];
   }

   if(dp[color_idx][house_idx]) {
      return dp[color_idx][house_idx];
   }

   int minCost  = INT_MAX;
   for(int i = 0; i < COLOR_COUNT; i++) {
      // we start from last house and for last house, we need to check for all colors
      if(house_idx == HOUSE_COUNT-1){
        int ans = color_cost[i][house_idx] + MinCost(color_cost, house_idx-1, i, dp);
        if(ans < minCost) {
           minCost = ans;
        }
      } else if(i != color_idx) {  // we need to exclude the previous house color 
          int ans = color_cost[i][house_idx] + MinCost(color_cost, house_idx-1, i, dp);
          if(ans < minCost) {
            minCost = ans;
          }
      }
   }

   dp[color_idx][house_idx] = minCost;
   return minCost;
}

int main()
{
   // color_cost table
   int color_cost[COLOR_COUNT][HOUSE_COUNT] = { {1,2,1,1},
                                                {1,3,2,2},
                                                {1,4,3,1}};  
   // create dp table
   int** dp = new int*[COLOR_COUNT];
   for(int i = 0; i < COLOR_COUNT; i++) {
      dp[i] = new int[HOUSE_COUNT];
   }

   // Calculate min color cost
   int minCost =  MinCost(color_cost, HOUSE_COUNT-1, 0, dp);  // In this call color_idx is dummy(0)

   cout<<"Min Cost to color the houses: "<<minCost<<endl; 
   
   return 0;
}
