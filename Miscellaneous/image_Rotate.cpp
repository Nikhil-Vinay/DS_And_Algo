/********* Rotate an matrix leftward or rightward **************************/
/** A two dimensional matrix is considered as an pixel image.
 ** A R-G-B pixel image is actually a 3-D matrix.
    All three color R, G and B represents a dimension and each pixel is an coordinate for the image.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Method-1: Take an array of size N, fill one row in the array and replace the column with array, then column
//           with row ...N times. rpeat same for each layer of matrix. It takes O(N) space
// Method-2: Similar to method-1, take a variable and rotate one by one element of a row. It takes O(1) space but
//           still not promising.
// Method-3: Best approach.
//           reverse all the rows then take transpose of matrix. Done..:)
//
// the below code is to rotate by 90 degree leftwards
// same can be applied for rightward rotation also.
//
template<size_t N>
void RotateLeft(int (&mat) [N][N])
{
   // Reverse all the rows
   for(int i = 0; i < N; i++) {
      int start = 0, end = N-1;
      while(start < end) {
         swap(mat[i][start], mat[i][end]);
         start++;
         end--;
      }
   }

   // take transpose of matrix(keep diagonal as it is. swap mat[i][j] with mat[j][i])
   // here diagonal is top-left to bottom-right
   // swap lower triangle elements with upper triangle elements
   for (int i = 0; i < N; i++) {
       int j = 0;
       while(j < i) {
          swap(mat[i][j], mat[j][i]);
          j++;
       }
   }
}

template<size_t N>
void RotateRight(int (&mat) [N][N])
{
   // Reverse all the rows 
   for(int i = 0; i < N; i++) {
      int start = 0, end = N-1;
      while(start < end) {
         swap(mat[i][start], mat[i][end]);
         start++;
         end--;
      }   
   }   

   // This is very tricky..
   // here diagonal is top-right to bottom-left
   // direct transpose is not applicable here, we need to swap elements of right lower triangle with
   // left upper triangle in transpose fashion. Nee to dry run for 4x4 matrix then will be aware of 
   // complexity.
   // We need to consider(hypothetically) as our matrix index start from top-right corner and row count will 
   // increase as it is from top to bottom but column count will increase from right to left.
   // 
   // We can see by dry run, if hypothetical coordinate is [i,j] then real coordinate will be [i, N-j-1]
   // Then, we will similarly work as transpose means will swap mat[i,j] with mat[j,i]
   //
   for (int i = 0; i < N; i++) {
       int j = 0;
       while(j < i) {
          swap(mat[i][N-j-1], mat[j][N-i-1]);
          j++;
       }
   }
}

template<size_t N>
void PrintMatrix(int (&mat) [N][N])
{
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         if ((mat[i][j] / 10) == 0) {
            cout<<mat[i][j]<<"  ";    
         } else {
            cout<<mat[i][j]<<" ";
         }
      }
      cout<<endl;
   }
   cout<<endl;
}

int main()
{
   int mat[4][4] = {{1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15, 16}};
   PrintMatrix(mat);
   cout<<"After 90 degree letward rotation: "<<endl;
   RotateLeft(mat);
   PrintMatrix(mat);
   cout<<"After 90 degree rightward rotation: "<<endl;
   RotateRight(mat);
   PrintMatrix(mat);
   return 0;
}
