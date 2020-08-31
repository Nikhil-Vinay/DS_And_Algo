/************** Find Number Of Island In A Matrix *****************************/

/** This problem was asked by Amazon.
 * Given a matrix of 1s and 0s, return the number of "islands" in the matrix. A 1 represents land and 0 
 * represents water, so an island is a group of 1s that are neighboring whose perimeter is surrounded by water.
 * Example: 
 * 1 0 0 0 0
 * 0 0 1 1 0
 * 0 1 1 0 0
 * 0 0 0 0 0
 * 1 1 0 0 1
 * 1 1 0 0 1
 *
 * Number Of Islands: 4
 */

/* Note: Variant of this problem: 
 * Find out number of 1s in the biggest island.
 */

/* Note: This problem can be solved by BFS or DFS but I would prefer DFS here */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define DIR_COUNT 8
int direction_x[DIR_COUNT] = {1, 0, -1, 0, 1, -1, -1,  1};
int direction_y[DIR_COUNT] = {0, 1, 0, -1, 1,  1, -1, -1};

template<size_t M, size_t N>
bool IsSafe(int (&mat)[M][N], int** visited, int rowIdx, int colIdx)
{
  return ((rowIdx >= 0) && (rowIdx < M) &&
          (colIdx >= 0) && (colIdx < N) && mat[rowIdx][colIdx] && (visited[rowIdx][colIdx] == 0));
}

template<size_t M, size_t N>
void DFS(int (&mat)[M][N], int** visited, int rowIdx, int colIdx)
{
   visited[rowIdx][colIdx] = 1;
   // check in all eight directions
   for(int i = 0; i < DIR_COUNT; i++) {
      if(IsSafe(mat, visited, rowIdx + direction_x[i], colIdx + direction_y[i])) {
         DFS(mat, visited, rowIdx + direction_x[i], colIdx + direction_y[i]);
      }
   }
}

template<size_t M, size_t N>
int GetIslandCount(int (&mat)[M][N])
{
   int count = 0;
   // create visited matrix for DFS
   int **visited = new int*[M];
   for(int i = 0; i < M; i++) {
      visited[i] = new int[N];
   }

   for(int i = 0; i < M; i++) {
      for(int j = 0; j < N; j++) {
         if(mat[i][j] && !visited[i][j]) {
            DFS(mat, visited, i, j);
            count++;
         }
      }
   }
   return count;
}

int main()
{
   int mat[6][5] = {{1, 0, 0, 0, 0},
                    {0, 0, 1, 1, 0},
                    {0, 1, 1, 0, 0},
                    {0, 0, 0, 0, 0},
                    {1, 1, 0, 0, 1},
                    {1, 1, 0, 0, 1}};

   cout<<"Number Of Islands: "<<GetIslandCount(mat)<<endl;
 
   return 0;
}
