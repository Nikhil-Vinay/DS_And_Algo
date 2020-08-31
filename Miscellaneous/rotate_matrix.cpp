/***************** Rotate the given matrix clockwise **************************/

/** Suppose given matrix is:
 *  1 2 3 4
 *  5 6 7 8
 *  1 2 3 4
 *  5 6 7 8
 *
 *  After 90 degree clock-wise rotation:
 *  5 1 5 1
 *  6 2 6 2
 *  7 3 7 3
 *  8 4 8 4
 *
 */

/* Note: I see the below method of rotation is better implementaion as , it can handle one digit shifting also
 * instead of 90 degree rotation, we can handle any kind of rotation by this method. */

/* Note: This method performs as first rotate the outer cell of the matrix and then rotate inner cell of the 
 * matrix one by one on the same principle.
 */

/* Note: Another for of the similar question is: Print the clockwise spiral form the matrix. 
 * This is solved in similar fashion as first print the clockwise spiral form of outer cell of the matrix the
 * print inner cell of the matrix one by one on the same principle.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void PrintArr(int** arr, int row, int col);

enum direction_e
{
  RIGHT,
  DOWN,
  LEFT,
  UP
};

void rotateMatrix(int** arr, int row, int col, int start_index_row, int start_index_col)
{
   // check if matrix is square
   if (row != col) {
      cout<<"Matrix is not square"<<endl;
      return;
   }

   // for 90 degree clockwise rottion, it needs row-1 iteration.
   int iteration_count = 1;
   int direction = RIGHT;
   int i = 0, j = 0;
   int temp = 0, last = 0;

   while(iteration_count <= row-1) {
      direction = RIGHT;
      i = start_index_row;
      j = start_index_col;
      last = arr[i][j];
      while(!((direction == UP) && (i == start_index_row) && (j == start_index_col))) {
         switch(direction) {
            case RIGHT:
                 j = j+1;
                 break;
            case DOWN:
                 i = i+1;
                 break;
            case LEFT:
                 j = j-1;
                 break;
            case UP:
                 i = i-1;
                 break;
            defaut:
                 break;
         }
         if ((direction == RIGHT) && (j == (start_index_col+col-1))) {
              direction = DOWN;
         } else if ((direction == DOWN) && (i == (start_index_row+row-1))) {
              direction = LEFT;
         } else if ((direction == LEFT) && (j == start_index_col)) {
              direction = UP;
         }
         temp = arr[i][j];
         arr[i][j] = last;
         last = temp;
      }
      iteration_count++;
   }
}

void PrintArr(int** arr, int row, int col)
{
  for(int i = 0; i < row; i++) {
     for(int j = 0; j < col; j++) {
        if((j > 0) && ((arr[i][j-1] / 10) == 0)) {
           cout<<"   "<<arr[i][j];
        } else {
           cout<<"  "<<arr[i][j];
        }
      }
      cout<<endl;
   }
}

int main()
{
  int row = 4, col = 4;

  int** arr = new int*[row];
  for(int i = 0; i < row; i++) {
     arr[i] = new int[col];
  }
  int k = 1;
  for(int i = 0; i < 4; i++) {
     for(int j = 0; j < 4; j++) {
        arr[i][j] = k++;
     }
  }

  int row_count = row;
  int col_count = col;

  int start_index_row = 0;
  int start_index_col = 0;

  PrintArr(arr, row, col);
  while(row_count >= 1 && col_count >= 1) {
    rotateMatrix(arr, row_count, col_count,  start_index_row, start_index_col);
    // cut top-bottom row and left-right column
    row_count -= 2;
    col_count -= 2;
    start_index_row += 1;
    start_index_col += 1;
  }
  cout<<"Array after rotation: "<<endl;
  PrintArr(arr, row, col);
  return 0;
}
