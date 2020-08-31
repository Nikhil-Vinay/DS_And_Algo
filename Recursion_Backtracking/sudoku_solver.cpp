/****************** SUDOKU SOLVER **************************/
/** A sudoku grid is given with n x n grid. n is always a perfect square.
 *  some elements are filled in sudoku cells in such a way that it could be solved by applying sudoku rules.
 *  Display the solved sudoku grid.
 */

/* Note: 
 * Following things we need to keep in my mind to solve tis prob.
 * 1. If sudo is n x n (n total number of cells), then there will be n boxes in sudoku and each box will contain
 *    n cells.
 * 2. Find out box indices.
 * 3. Find out box starting position with help of any cell in the sudoku list.
 * 4. Number of rows and cols in each sudoku box = sqrt(n)
 */

/* Note: very important Check for applying bit masking in IsPossisble function */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef struct Pos_t
{
  int x;
  int y;
}Pos_t;

int BoxRowIndex(int cell_pos_x, int row_col_box_count)
{
  return (cell_pos_x/row_col_box_count);
}

int BoxColIndex(int cell_pos_y, int row_col_box_count)
{
  return (cell_pos_y/row_col_box_count);
}

int BoxStartCellRowIndex(int box_row_index, int row_col_box_count)
{
  return box_row_index * row_col_box_count;
}

int BoxStartCellColIndex(int box_col_index, int row_col_box_count)
{
  return box_col_index * row_col_box_count;
}

bool IsPossible(int (&arr)[4][4], int n, int row, int col, int number) {
/* For nxn sudoku, if need to have below three array for row, col and boxes
 * int row[n], col[n], box[n];
 * bitn of row[i] will represent whether row[i] has n or not.
 * bitn of col[i] will represent whether col[i] has n or not.
 * bitn of box[i] will represent whether box[i] has n or not.
 *
 * We need to set/reset bits accordingly while moving cell to cell and backtracking.
 *
 * By this way, if we need to check for number(n) in row(i), col(j) and box(k) then we'll do as below:
 * if (((1<<n) & row[i]) || ((1<<n) & col[i]) || ((1<<n) & box[i])) {
 *     return false;
 * } else {
 *     return true;
 * }
 *
 * This way we can reduce time complexity of this function to O(1) instead of O(3n)~O(n) as below.
 */
   // check for rows
   for(int i = 0; i < n; i++) {
       if(arr[row][i] == number) {
          return false;
       }  
   }

   // check for columns
   for(int i = 0; i < n; i++) {
      if(arr[i][col] == number) {
        return false;
      }
   }

   // check for box
   int row_col_box_count = sqrt(n);
   int box_row_index = BoxRowIndex(row, row_col_box_count);
   int box_col_index = BoxColIndex(col, row_col_box_count);

   int box_start_cell_row_index = BoxStartCellRowIndex(box_row_index, row_col_box_count);
   int box_start_cell_col_index = BoxStartCellColIndex(box_col_index, row_col_box_count);

   for(int i = box_start_cell_row_index; i < (box_start_cell_row_index + row_col_box_count); i++) {
      for(int j = box_start_cell_col_index; j < (box_start_cell_col_index + row_col_box_count); j++) {
         if(arr[i][j] == number) {
            return false;
         }
      }
   }

   return true;
}

bool SolveSudoku(int (&arr)[4][4], int n, int row, int col)
{
  if(row == n-1 && col == n-1) {
     return true;
  }

  if(arr[row][col] != 0) {
     if((col+1) < n) {
       return SolveSudoku(arr, n, row, col+1);
     } else if ((row+1) < n){
       return SolveSudoku(arr, n, row+1, 0);
     } else {
       return true;
     }
  } else {
    for(int i = 1; i <= n; i++) {
       if(IsPossible(arr, n, row, col, i)) {
          arr[row][col] = i;
          bool done = false;
          if((col+1) < n) {
             done =  SolveSudoku(arr, n, row, col+1);
          } else if ((row+1) < n){ 
             done =  SolveSudoku(arr, n, row+1, 0); 
          }
 
          if(done) {
            return true;
          }
          // if not done then let it go for backtracking by next element of for loop
       }
    }
  }

  return false;
}

int main()
{
   int arr[4][4] = { {3, 4, 1, 0},
                     {0, 2, 0, 0},
                     {0, 0, 2, 0},
                     {0, 1, 4, 3}};
   if(SolveSudoku(arr, 4, 0, 0)) {
      cout<<"Solution of given sudoku is :"<<endl;
      for(int i = 0; i < 4; i++) {
         for(int j = 0; j < 4; j++) {
            cout<<arr[i][j]<<" ";
         }
         cout<<endl;
      }
   } else {
     cout<<"This grid of sudoku can't be solved, Insufficient data"<<endl;
     for(int i = 0; i < 4; i++) {
         for(int j = 0; j < 4; j++) {
            cout<<arr[i][j]<<" ";
         }
         cout<<endl;
      } 
   }
   return 0;
}
