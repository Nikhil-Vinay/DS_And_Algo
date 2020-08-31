/******** COlor filling problem, ms paint works on same logic ********/
/******** It is nothing bu DFS **********************/
/******** In below prog, we are populating array by user input, better read input from any file and populate*/

#include<iostream>
#include<vector>
#include<list>

using namespace std;

void PrintArr(char arr[][150], int row, int col)
{
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
      cout<<arr[i][j];

      cout<<endl;
  }
  cout<<endl;
}

void colorfill(char arr[][150], int row, int col ,int i, int j)
{

  if(j < 0 || j >= col || i < 0 || i >= row || arr[i][j] != '.')
     return;

  arr[i][j] = '@';
  //PrintArr(arr, row, col);
  //usleep(50000);
  colorfill(arr, row, col, i+1, j);
  colorfill(arr, row, col, i, j+1);
  colorfill(arr, row, col, i-1, j);
  colorfill(arr, row, col, i, j-1);
  return;
}

int main()
{
  char arr[150][150] = {'\0'};

  int row = 40, col=120;

  for(int i = 0; i < 40; i++)
  {
    for(int j = 0; j < 120; j++)
    {
      cin>>arr[i][j];
    }
  }

  PrintArr(arr, row, col);

  colorfill(arr, row, col, 20, 60);  // just giving 20, 60 any random number

  PrintArr(arr, row, col); 
  
}
