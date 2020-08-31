/********* RAT IN A MAZE PROBLEM **********************************/

/* There is matrix of nxn or mxn. Matrix has combination of 0 & 1 integers. A rat is sitting at (0,0).
 * We need to print all the path from (0,0) to (n-1, n-1) so rat can reach there. cells having 0 is blocked cell.
 * Rat can move up, down, left and right */

/* Note: Whenever we need to print all paths in a matrix, we have to explore all paths so never think about
 * time complexity, DP or etc. Explore all paths and print it.
 * If we need to find number of ways to reach then we can look into DO solution. */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void PrintPathArray(int** path_arr, int n) 
{
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
       cout<<path_arr[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}

void PrintRatInMazePath(int maze[][6], int** path_arr, int n, int x, int y)
{
  if(x == n-1 && y == n-1) {
    path_arr[x][y] = 1;
    PrintPathArray(path_arr, n);
    path_arr[x][y] = 0;
    return;
  }

  path_arr[x][y] = 1;

  if (x-1 >= 0 && maze[x-1][y] && path_arr[x-1][y] == 0) {
    PrintRatInMazePath(maze, path_arr, n, x-1, y);
  }
  if(x+1 < n && maze[x+1][y] && path_arr[x+1][y] == 0) {
    PrintRatInMazePath(maze, path_arr, n, x+1, y);
  }
  if(y-1 >= 0 && maze[x][y-1] && path_arr[x][y-1] == 0) {
    PrintRatInMazePath(maze, path_arr, n, x, y-1);
  }
  if(y+1 < n && maze[x][y+1] && path_arr[x][y+1] == 0) {
    PrintRatInMazePath(maze, path_arr, n, x, y+1);
  }
  
  path_arr[x][y] = 0;  // back tracking, set it to zero for exploring other paths from nodes visited before this
  return;

}

int main()
{
   int maze[6][6] = { {1, 1, 1, 0, 1, 1 },
                      {1, 0, 1, 0, 0, 1 },
                      {1, 1, 1, 1, 0, 1 },
                      {1, 0, 1, 1, 0, 1 },
                      {1, 1, 1, 1, 1, 1 },
                      {1, 0, 1, 0, 0, 1 }};

   int **path_arr = new int*[6];
   for(int i = 0; i < 6; i++) {
      path_arr[i] = new int(0);
   }

   PrintRatInMazePath(maze, path_arr, 6, 0, 0);
   return 0;
}
