/**************** N Queen problem (How many ways to place N queens in NxN matrix ********************/
/**************  Beautiful example of back tracking problem *******************************/

#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

int maxval = 0;

bool IsSafe(int** ptr, int row, int index, int n)
{
  // Check for col safe
  for(int i = 0; i < row; i++)
  {
    if(ptr[i][index] == 1)
    {
      return false;
    }
  }

  //if(safe)
  //{
     // check for left diagonal
    int diagindex = index-1;
    int rowindex = row-1;
    while(diagindex >= 0 && rowindex >= 0)
    {
      if(ptr[rowindex][diagindex] == 1)
      {
        return false;
      }
      rowindex--;
      diagindex--;
    }
    // check for left diagonal
    diagindex = index+1;
    rowindex = row-1;
    while(diagindex < n && rowindex >= 0)
    {
      if(ptr[rowindex][diagindex] == 1)
      {
        return false;
      }
      rowindex--;
      diagindex--;
    }
  return true;
} 

int Solve(int **ptr, int row, int n)
{
  if(row >= n)
  {
    maxval++;
    return 1;
  }
   
  int ways = 0;
  for(int i = 0; i < n; i++)
  {
    if(IsSafe(ptr, row, i, n))
    {
      //update the matrix
      ptr[row][i] = 1;
      ways += Solve(ptr, row+1, n);
      ptr[row][i] = 0;
    }
  }


  return ways;
}

int main()
{
  int n;
  cout<<"Enter the number of row/col: "<<endl;
  cin >> n;

  int** ptr = new int*[n];
  for(int i = 0; i < n; i++)
    ptr[i] = new int[n];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        ptr[i][j] = 0;

  cout<<"Numver of ways: "<<Solve(ptr, 0, n)<<endl;
cout<<maxval<<endl;
}

