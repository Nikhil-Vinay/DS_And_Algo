/******************* Find Number Of Islands ********************/
/*  Excellent example of DFS
    {1, 1, 0, 0, 0},
    {0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1},
    {0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1}

 A group of connected 1s forms an island.
 Here number of islands are - 5 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int island_count = 0;

bool IsValidIndex(int rowindex, int colindex, int row, int col)
{
  return (rowindex >= 0 && rowindex < row && colindex >= 0 && colindex < col); 
}

void DFS(int arr[][5], int** visited, int rowindex, int colindex, int row, int col)
{
   if(!IsValidIndex(rowindex, colindex, row, col)){
      return;
   }

   if(visited[rowindex][colindex] == 1 || arr[rowindex][colindex] == 0) {
      return;
   }

   visited[rowindex][colindex] = 1;
   DFS(arr, visited, rowindex+1, colindex, row, col);
   DFS(arr, visited, rowindex-1, colindex, row, col);
   DFS(arr, visited, rowindex, colindex+1, row, col);
   DFS(arr, visited, rowindex, colindex-1, row, col);
   DFS(arr, visited, rowindex+1, colindex+1, row, col);
   DFS(arr, visited, rowindex-1, colindex-1, row, col);
   DFS(arr, visited, rowindex-1, colindex+1, row, col);
   DFS(arr, visited, rowindex+1, colindex-1, row, col);
   return;
}

int GetIslandCount(int arr[][5], int row, int col)
{
  int **visited = new int*[row];
  for(int i = 0; i < row; i++) {
      visited[i] = new int[col];
  }

  for(int i = 0; i < row; i++) {
     for(int j = 0; j < col; j++) {
        if(visited[i][j] == 0 && arr[i][j] == 1) {
           DFS(arr, visited, i, j, row, col);
           island_count++;
        }
     }
  }

  // delete visited array
  for(int i = 0; i < row; i++) {
      delete visited[i];
  }
  delete visited;

  return island_count;
    
}

int main()
{
   int arr[5][5] = {{1, 1, 0, 0, 0},
                    {0, 1, 0, 0, 1},
                    {1, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0},
                    {1, 0, 1, 0, 1}};


   cout<<"Number of islands are = "<<GetIslandCount(arr, 5, 5)<<endl;
   return 0;
}
