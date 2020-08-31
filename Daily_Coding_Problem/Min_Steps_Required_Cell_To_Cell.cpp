/* 
 * You are given an M by N matrix consisting of booleans that represents a board. Each true boolean represents a
 * wall. Each false boolean represents a tile, you can walk on.
 * Given the matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to
 * reach the end coordinate from the start.If there is no possible path, then return 0. You can move up, left,
 * down and right. You cannot move through walls. You cannot wrap around the edges of the board.
 */

/* Note: A very importatnt note:
 *
 * Whenever we can move in all four directions, we can't solve it by DP(top-down or ottom up approach).
 * For Bottom up approach, we can't fill the base condition(0th column and 0th row) because at any cell of 0th
 * row or 0th column, we can come from two sides.
 * For Top-Down approach, it will become cyclic and finally core dump will happen because of stack overflow.
 * Suppose we are cell (x,y). To save the solution of this coordinate we need solution for all four adjascent
 * cells. We will go up, then left, then down, then right ... we reach at same cell again and nothing is memoize
 * d as of now because we don't have solution yet, we are just discovering in one direction. So this is called
 * cyclic problem.
 *
 * Verdict: If we need to explore in all four direction, it is not a DP problem. It is similar to rat in a maze
 * problem, which will be solved by back-tracking. The below solution implements the same.
 *
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Point
{
  public:
  int x;
  int y;
  Point(int in_x, int in_y):x(in_x), y(in_y) { };
};

template<typename T, size_t M, size_t N> 
void MinSteps(T (&arr)[M][N], Point start, Point end, int** path_arr, int &step_count, int &min_step_count)
{
   // base condition,
   if((start.x == end.x) && (start.y == end.y)) {
      if(step_count < min_step_count) {
         min_step_count = step_count;
      }
      return;
   }

   int x = start.x;
   int y = start.y;

   path_arr[x][y] = 1;
   step_count++;

   // Check for up
   if((y-1 >= 0) && (arr[x][y-1] == false) && (path_arr[x][y-1] == 0)) {
     MinSteps(arr, Point(x, y-1), end, path_arr, step_count, min_step_count);
   }   
   // Check for down
   if((y+1 < M) && (arr[x][y+1] == false) && (path_arr[x][y+1] == 0)) {
     MinSteps(arr, Point(x, y+1), end, path_arr, step_count, min_step_count);
   } 
   // check for left
   if((x-1 >= 0) && (arr[x-1][y] == false) && (path_arr[x-1][y] == 0)) {
     MinSteps(arr, Point(x-1, y), end, path_arr, step_count, min_step_count);
   }
   // check for right
   if((x+1 < N) && (arr[x+1][y] == false) && (path_arr[x+1][y] == 0)) {
     MinSteps(arr, Point(x+1, y), end, path_arr, step_count, min_step_count);
   }

   // backtrack
   path_arr[x][y] = 0;
   step_count--;

   return;  
}

int main()
{
  bool grid[4][4] = { {false, false, false, false},
                      {true, true, false, true},
                      {false, false, false, false},
                      {false, false, false, false}};

  Point start(3,0);
  Point end(0,0);

  int** path_arr = new int*[4];
  for(int i = 0; i < 4; i++) {
    path_arr[i] = new int[4];
  }
   
  int step_count = 0;
  int min_step_count = INT_MAX;
                   
  MinSteps(grid, start, end, path_arr, step_count, min_step_count);
  cout<<"Minimum number of steps is: "<<min_step_count<<endl;
  return 0;
}
