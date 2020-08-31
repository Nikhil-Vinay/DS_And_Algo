/************** Min Number Of Coins ************************/

/*** There are n types of infine coins, We need to find minimum number of coins used to make a specific value.
 * This prob is min num of coin for coin changing problem also.
 * Ex: Coins are : 7, 5, 6, 2, 1 (Infinite number of all denominations).
 * Val: 11.
 * Greedy solution : 7, 2, 2 (First pick the highest value and so o...)
 * DP Solution: 6, 5 (Two coins)
 */

/* Time complexity is - O(sum) //
 * We can trace dry run tree diagram 
 *
 * recursive brute force will take exponential time*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
/******** Recursive solution **************/

int coinsNeeded(int coins[], int amount, int n, int* dp)  // only amount is variable so using 1-d dp
{
   // base case
   if(amount == 0) {
     return 0;
   }

   if(dp[amount] != INT_MAX) {
      return dp[amount];
   }
   int ans = INT_MAX;
  
   for(int i = 0; i < n; i++) {
     // think for 2 mins
     if(amount - coins[i] >= 0) {
        int smallerAns = coinsNeeded(coins, amount - coins[i], n, dp);
        if(smallerAns != INT_MAX) {
           ans = min(ans, smallerAns+1);
        }
     }
   }

   dp[amount] = ans;
   return ans;
}

void coinsNeeded2(int coins[], int amount, int n)
{
   // dp table
   vector<int> dp;
   dp.resize(amount + 1);
   for(int i = 0; i <= amount; i++) {
      dp[i] = INT_MAX;
   }

   dp[0] = 0;

   for(int i = 1; i <= amount; i++){
       int res = INT_MAX;
       for(int j = 0; j < n; j++) {
          if(coins[j] <= i && ((i-coins[j]) >= 0)) {
             if(dp[i-coins[j]] != INT_MAX) {
                res = min(res, 1 + dp[i - coins[j]]);
             }
          }
       }
       dp[i] = res;
   }

   if(dp[amount] != INT_MAX) {
      cout<<"Minimum number of coins needed = "<<dp[amount]<<endl;
   } else {
      cout<<"Making change is not possible"<<endl;
   }

   map<int, int> m;
   // sort coins in descending order
   sort(coins, coins+n, greater<int>()); 
   while(amount > 0) {
       int coin_count = dp[amount];
       for (int j = 0; j < n; j++){
           if ( ((amount - coins[j]) >= 0 ) && dp[amount - coins[j]] == (coin_count - 1)){
               if(m.find(coins[j]) == m.end()){
                  m.insert(make_pair(coins[j], 1));
               } else {
                  m[coins[j]]++;
               }
               amount -= coins[j];
           }
       }
   }

   cout<<"coins selected: "<<endl;
   map<int, int>::iterator it;
   for(it = m.begin(); it != m.end(); it++) {
       cout<<"coin: "<<it->first<<" count: "<<it->second<<endl;
   }
   return;
}

/* The above solution is similar to staircase solution. It ca be represented as below:
 * MinCoins(sum) = Min(MinCoins(Sum-D0), MinCoins(Sum-D1), ......., MinCoins(Sum-Dn));
 *
 * Here we check if(Dn < Sum) before calling - MinCoins(Sum-Dn) to avoid unnecessary calls else it can also be
 * handled in base case.
 *
 * Dry run (inverted tree) will depict the same.
 * Here, in each iteration we keep num of coins same only we change the total sum. It means we look into all
 * repetive solution as (1, 2, 2), (1, 2, 1) and (2, 1, 1). It makes out dp one dimensional though wen we find
 * unique number of ways to get the sum, it doesn't allow repetitive soln so dp becomes 2-D (look into this prob)
 */

/******* Iterative solution ***************/
// can be solved iteratively easily by looking recursive solution by having proper base solution.
// This is called bottom up approach

int main()
{
  //int arr[5] = { 7, 5, 6, 2, 1 };
  int arr[2] = { 2, 1 };
  //int arr[3] = { 1, 7, 10};
  int n = sizeof(arr)/sizeof(arr[0]);
  int sum = 5;

  int *dp = new int(sum + 1);
  for(int i = 0; i <= sum; i++) {
     dp[i] = INT_MAX;
  }

  //int min_coin_count = coinsNeeded(arr, sum, n, dp);
  //cout<< "Minimum nuber of coins to get sum "<<sum<<" is - "<<min_coin_count<<endl;
  coinsNeeded2(arr, sum, n);

  return 0;
}
