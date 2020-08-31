#include<iostream>
#include<stdlib.h>
#include<climits>

using namespace std;

int knapsack(int price[], int wt[], int N, int W)
{
  if(N == 0)
     return 0;

  //int profit = INT_MAX;
  int select = 0;
  int reject = 0;

  if(wt[N-1] <= W)
  {
    // if you select an item, give all the option to select
    select = price[N-1] + knapsack(price, wt, N, W-wt[N-1]);
    // once an item is rejected, it can be selected again
    reject = knapsack(price, wt, N-1, W);
  }
  else
  {
    reject = knapsack(price, wt, N-1, W);
  }

  return(select >= reject ? select : reject);
}

int bottomUp(int price[], int wt[], int N, int W)
{
  int table[100][100] = {0};

  for(int i = 0; i <= N; i++)
  {
    for(int j = 0; j <= W; j++)
    {
      if(i == 0 || j == 0)
         table[i][j] = 0;
      else
      {
        int select = 0;
        int reject = 0;
        if(wt[j-1] >= wt[i-1])
        {
          select = price[i-1] + table[i][j-wt[i-1]];
        }
        reject = table[i-1][j];
        table[i][j] = (select > reject ? select : reject);
      }
    }
  }

  // Print the table

  return table[N][W];
}

int main()
{
  int price[] = { 5, 7, 10, 12 };
  int wt[] =    { 3, 2, 5, 10 };
  int N  = 4;
  int W = 7;

  int maxprofit = knapsack(price, wt, N, W);
  cout<<"Max Profit is: "<<maxprofit<<endl;
  maxprofit = bottomUp(price, wt, N, W);
  cout<<"Max Profit is: "<<maxprofit<<endl;
  return 0;
}
