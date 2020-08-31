



#include<iostream>
#include<bits/stdc++.h>

using namespace std;
template<size_t M, size_t N>
bool IsValidCell(char (&grid)[M][N], bool** visited, int rowIdx, int colIdx)
{
  if(rowIdx >= 0 && rowIdx < M && colIdx >= 0 && colIdx < N && visited[rowIdx][colIdx] == false) {
     return true;
  }
  return false;  
}

template<size_t M, size_t N>
bool FindWordInGridUtil(char (&grid)[M][N], string word, int strIdx, bool** visited, int rowIdx, int colIdx)
{
   if(strIdx == word.length()) {
     return true;
   }

   if(grid[rowIdx][colIdx] != word.at(strIdx)) {
      return false;
   }

   visited[rowIdx][colIdx] = 1;
   // check in all four directions
   bool test1 = false, test2 = false, test3 = false, test4 = false;
   if(IsValidCell(grid, visited, rowIdx+1, colIdx)) {
      test1 = FindWordInGridUtil(grid, word, strIdx+1, visited, rowIdx+1, colIdx);
   }
   if(IsValidCell(grid, visited, rowIdx-1, colIdx)) {
      test2 = FindWordInGridUtil(grid, word, strIdx+1, visited, rowIdx-1, colIdx);
   }
   if(IsValidCell(grid, visited, rowIdx, colIdx+1)) {
      test3 = FindWordInGridUtil(grid, word, strIdx+1, visited, rowIdx, colIdx+1);
   }
   if(IsValidCell(grid, visited, rowIdx, colIdx-1)) {
      test4 = FindWordInGridUtil(grid, word, strIdx+1, visited, rowIdx, colIdx-1);
   }
  
   // baxktracking
   visited[rowIdx][colIdx] = 0;

   return test1 || test2 || test3 || test4;   
}

void RsesetVisitedArray(bool **visited, int M, int N)
{
   for(int i = 0; i < M; i++) {
      for(int j = 0; j < N; j++) {
        visited[i][j] = false;
      }
   }
}

template<size_t M, size_t N>
bool FindWordInGrid(char (&grid)[M][N], string word)
{
   bool found = false;
   bool **visited = new bool*[M];
   for(int i = 0; i < M; i++) {
      visited[i] = new bool[N];
   }
 
   for(int i = 0; i < M; i++) {
      for(int j = 0; j < N; j++) {
         RsesetVisitedArray(visited, M, N);        
         if(found = FindWordInGridUtil(grid, word, 0, visited, i, j)) {
            break;
         }
      }
      if(found) {
        break;
      }
   }
   return found;
}

int main()
{
    char grid[3][4] =  {
                         {'A','B','C','E'},
                         {'S','F','C','S'},
                         {'A','D','E','E'}
                       };
#if 1
    //if(FindWordInGrid(grid, "ABCCED")) {
    //if(FindWordInGrid(grid, "SEE")) {
    if(FindWordInGrid(grid, "ABCB")) {
      cout<<"Word is found"<<endl;
    } else {
      cout<<"Word is not found"<<endl;
    }
#endif
    return 0;
}
