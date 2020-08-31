/* Given an array of integers nums, and a target sum T.
 * You need to find the number of ways you can get target sum using add/substract of the array elements together.
 *
 * Example: 1  1  1  1  1     Target sum = 3
 * Sol:     1  1  1  1 -1
 *          1  1  1 -1  1
 *          1  1 -1  1  1
 *          1 -1  1  1  1
 *         -1  1  1  1  1
 *
 *         Total number of ways = 5
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int dp[200][200] = {0};

template<size_t N>
int NumberOfWays(int (&nums)[N], int target, int idx, int sum)
{
   if(idx == N && sum == target){
     return 1;
   }

   if(idx >= N){
      return 0;
   }

   // nums[idx] could be + or negative
   int sol1 = NumberOfWays(nums, target, idx+1, sum + nums[idx]);
   int sol2 = NumberOfWays(nums, target, idx+1, sum + (-1)*nums[idx]);

   dp[idx][sum] = sol1+sol2;  
   return sol1 + sol2;

}

int main()
{
  int nums[5] = {1, 1, 1, 1, 1};
  int target = 3;
  cout<<"Number Of Ways: "<<NumberOfWays(nums, target, 0, 0)<<endl;
  return 0;
}         
