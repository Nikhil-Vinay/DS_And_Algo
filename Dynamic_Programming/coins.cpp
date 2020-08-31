#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<size_t N>
int MinNumCoins(int (&coins)[N], int n, int* &dp)
{
   if(n == 0) {
     return 0;
   }

   if(dp[n] != -1) {
      return dp[n];
   }

   int mincoins = INT_MAX;
   for(int i = 0; i < N; i++) {
      if(coins[i] <= n) {
         mincoins = min(mincoins, 1+MinNumCoins(coins, n - coins[i], dp));     
      }
   }

   dp[n] = mincoins;
   return dp[n];
}

template<size_t N>
int MaxNumWays(int (&coins)[N], int idx, int n)
{
   // base condition
   if(n == 0) {
      return 1;
   }
   if(idx >= N || n < 0) {
      return 0;
   }

   int select = 0;
   int reject = 0;

   select = MaxNumWays(coins, idx, n-coins[idx]);
   reject = MaxNumWays(coins, idx+1, n);

   return select+reject;
}

int main()
{
  int coins[4] = { 9, 6, 5, 1 };
  int* dp = NULL;
  int n;
  dp = new int[n+1];
  for(int i = 0; i <= n; i++) {
     dp[i] = -1;
  }
  cout<<"Denominations are: { 9, 6, 5, 1 }, Please enter the amount to make change:"<<endl;
  cin >> n;
  cout <<"Min Num of coins required: "<<MinNumCoins(coins, n, dp)<<endl;
  cout <<"Num Of ways to make change: "<<MaxNumWays(coins, 0, n)<<endl; 
  return 0;
 
}
