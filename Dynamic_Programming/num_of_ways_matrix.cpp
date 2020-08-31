/* You are given an N by M matrix of 0s and 1s. Starting from the top left corner, how many ways are there to reach the bottom right corner?
 *
 * You can only move right and down. 0 represents an empty space while 1 represents a wall you cannot walk through.
 *
 *  For example, given the following matrix:
 *  [0, 0, 1],
 *  [0, 0, 1],
 *  [1, 0, 0]
 *  Return two, as there are only two ways to get to the bottom right:
 *
 *  Right, down, down, right
 *  Down, right, down, right
 *  The top left corner and bottom right corner will always be 0
 * /
 */   

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<size_t M, size_t N>
int NumOfWaysTopDown(int (&mat)[M][N], int (&dp)[M][N], int row, int col)
{
   if(row < 0 || row >= M || col < 0 || col >= N) {
     return 0;
   }

   if(row == 0 && col == 0) {
     return 1;
   }
 
   if(dp[row][col]) {
      return dp[row][col];
   }

   int solFromLeft=0, solFromTop = 0;
   if(col-1 >= 0 && mat[row][col-1]==0) {
      solFromLeft = NumOfWaysTopDown(mat, dp, row, col-1);
   }

   if(row-1 >= 0 && mat[row-1][col]==0) {
      solFromTop = NumOfWaysTopDown(mat, dp, row-1, col);
   }

   dp[row][col] = solFromLeft  + solFromTop;
   return dp[row][col];
}

int main()
{
   int mat[3][3] = {{0, 0, 1},
                    {0, 0, 1},
                    {1, 0, 0}};
    
   int dp[3][3] = {{0, 0, 0},
                   {0, 0, 0},
                   {0, 0, 0}};

   cout<<"Number Of Ways: "<<NumOfWaysTopDown(mat, dp, 2, 2)<<endl;
   return 0;
}
