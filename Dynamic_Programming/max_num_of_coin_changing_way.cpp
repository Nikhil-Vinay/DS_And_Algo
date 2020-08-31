/************ Max number of coin changing way ******************/

/*** There n denomination coins with infinite number. We need to find number of iunique ways for changing a 
 * coin value by using the existing denominations.
 * Ex: coins are: 1, 2
 * Val: 4
 * Different unique ways of changing: { 1,1,1,1}, { 1,1,2}, {2,2}
 * Total number of ways = 3
 *
 * based on inclusion, exclusion
 *
 * Note: 
 *
 * We can think as this can be solved like number of ways to reach by staircase prob, but think, in case
 * of staircase prob, ( 1, 1, 2) & (2, 1, 1) are two different ways.
 * But in this prob to find number of ways to make change, repetition is not allowed.
 * Here, (1, 1, 2) and ( 1, 2, 1), (2, 1, 1) are same.
 *
 * So, below solution is not proper:
 * NumOfWays(n) = NumOfWays(sum- D0) + NumOfWays(sum-D1) + ....NumOfWays(sum-Dn); // D0..Dn are denominations
 *
 * Note:
 * One prob is as - one player can throw dice and get 3, 5, 10 only so how many ways he get 30.
 * Number of ways to get 30 - (3, 10), (3,5,5), (5, 3, 5), (5, 5, 3), (10, 3) - total 5
 * So, Solution - NumofWays(n) = NumofWays(n-3) + NumofWays(n-5) + NumOfWays(n-10);
 *
 * Note:
 * It is very important to see whether same solution with shuffled number is allowed or not. If allowed then 
 * simply staircase solution will fit. if shuffled solution is not considered unique then the below solution will
 * be applicable.
 *
 * When we draw the dry run diagram (tree diagram), it becomes clear. We see in the above problemm - (1,1,2)
 * will be answer only in case we keep selecting 1 in our solution. When we select next element 2, it means we 
 * have excluded 1 from our solution so 1 will not come after 2 means (2, 1, 1) will never be a solution. So,
 * (1, 1, 2) and (2, 1, 2) wont come together as distinct solution. Similarly, (1, 2, 1) also wont be a solution.
 * because 1 can't come after 2.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int waysCount(int* arr, int n, int sum, int** dp)   // n and sum is changing, 2-d dp
{
   if(sum == 0) {
     return 1;
   }

   if((n <= 0) || (sum < 0)) {
     return 0;
   }
 
   if (dp[n][sum]) {
      return dp[n][sum];
   }

   int inc = waysCount(arr, n, sum-arr[n-1], dp);
   int exc = waysCount(arr+1, n-1, sum, dp);

   dp[n][sum] = inc + exc;
   return dp[n][sum];
}

int main()
{
  //int arr[2] = { 1, 2 };
  int arr[5] = { 1, 2, 5 };

  int sum = 5;

  int** dp = new int*[3];
  for(int i=0; i< 3; i++) {
    dp[i] = new int[sum+1];
  }
  int num_of_ways = waysCount(arr, sizeof(arr)/sizeof(arr[0]), sum, dp);
  cout<<"Number Of Ways: "<<num_of_ways<<endl;
  return 0;
}
