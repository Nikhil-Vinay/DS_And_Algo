/*************** Find maximum number of ways to place beicks in a field ***********/

/** There is field of dimension (N X 2 ), length - N, width - 2. There are infinite number of bricks of dimension
 *  (2 x 1 ). How many ways to fill the field by placing the bricks inside it ? Bricks can be placed horizontally
 *  or verically only/
 *
 *  This problem is derivative of fabonacci series problem.
 *
 *  Similar problem based on same concept: 
 *  1. There are n steps in a ladder, a person can climb one step or two step at a time. How many ways to climb
 *     on top of the ladder ?
 *  2. There are n coins denominations - D0, D1, D2...Dn. What would be minimum coin count to make change of
 *     sum - 'S'.
 *  3. There is dice which can give either D0, D1, D2...Dn in one throw. How may ways to achieve a number by 
 *     continuous throw of dice.
 *  4. fabonacci series: f(n) = f(n-1) + f(n-2)
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int NumWays(int n, int* dp) {
  if(n == 0) {
    return 0;
  }
  if(n < 0) {
    return 0;
  }
  if(n==1) {
    return 1;
  }
  if(n == 2) {
    return 2;
  }

  if(dp[n] > 0) {
     return dp[n];
  }

  dp[n] = NumWays(n-1, dp) + NumWays(n-2, dp);
  return dp[n];
}

// Can be solved iteratively easily

int main() 
{
   int n;
   cout<<"Please enter the grid length: "<<endl;
   cin>>n;
  
   int *dp = new int[n+1];
   cout<<"Number of ways of brick placement is : "<<NumWays(n, dp)<<endl;  
   delete[] dp;

   return 0;
}

/* Note: if grid is 4 x n and brick size is 4 x 1. Base condition is following
 * if(n <= 0) {
 *    return  0;
 * }
 *
 * if((n >= 1) && (n < 4)){  // if grid length is 1 to 3, then only one way to place brick
 *    return 1;
 * }
 * if(n == 4) {
 *    return 2;
 * }
 *
 * f(n) = f(n-1) + f(n-4);
 */

/* Base condition is very important in this kind of problem.
 * Suppose there are n steps in stair case and a person can take either 2 or 4 steps at a time then find how 
 * many ways to reach the top.
 *
 * Think for base case:
 *
 * if(n <= 1){   // no way to reach
 *    return 0;
 * }
 * if(n == 2) {  // one way to reach
 *    return 1;
 * if(n == 3) {  // no way to reach
 *   return 0;
 * }
 * If(n==4) {   // two ways to reach (4, 2+2)
 *   return 2;
 * }
 *
 * // for more than 4 steps, let it be calculated by recursive calls.
 * f(n) = f(n-2) + f(n-4);   // we will define f(n) by only subsolutions which is giving > 0 result.
 */                     
 
