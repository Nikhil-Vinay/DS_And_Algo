/** Knight move on chess board **/

/* This is a classic problem based on recursion and backtracking. If board is of size NxN then it is proved that a knight can complete the all cells og the board in (NxN-1) times. A knight can move 2 and half in all 8 directions.
 * We need to return the board with move number filled in the cells of the board.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template <size_t N>
bool IsValidMove(int (&board)[N][N], int rowIdx, int colIdx) {
   return ( rowIdx >= 0 && rowIdx < N && colIdx >= 0 && 
             colIdx < N && board[rowIdx][colIdx] == -1);
}

template<size_t N>
bool SolveKnightMoveBoard(int (&board)[N][N], int rowIdx, int colIdx, int movecount)
{
   int next_row, next_col;
   if(movecount == (N*N)) {
      return true;
   }

   // knight move array
   int x_move[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };  
   int y_move[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

   for(int i = 0; i < 8; i++) {
      next_row = rowIdx + x_move[i];
      next_col = colIdx + y_move[i];
      if(IsValidMove(board, next_row, next_col)) {
         board[next_row][next_col] = movecount;
         bool ret = SolveKnightMoveBoard(board, next_row, next_col, movecount+1);
         if(ret == true){   // board is solved
            return true;
         } else {
            board[next_row][next_col] = -1;  // backtracking
         } 
      }
   }
   return false;
} 

template <size_t N>
void PrintBoard(int (&board)[N][N])
{
   for(int i = 0; i < N; i++) {
       for(int j = 0; j < N; j++) {
          cout<<setw(3)<<board[i][j];
       }
       cout<<endl;
   }
}

int main()
{ 
   int board[8][8];
   for(int i = 0; i < 8; i++) {
      for(int j = 0; j < 8; j++) {
         board[i][j] = -1;
      }
   }
   board[0][0] = 0;
   if (SolveKnightMoveBoard(board, 0, 0, 1)) {
      PrintBoard(board);
   } else {
     cout<<"Sol is not possible"<<endl;
   }
   return 0;
}
