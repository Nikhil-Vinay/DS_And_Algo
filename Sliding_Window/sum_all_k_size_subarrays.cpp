/***** Find sum of all subarrays of size k *******/
/* If n is size of array then 1 <= K <= n */

/* Note: sliding window is different technique at all, its not dynamic programming */

/* Note: This sliding window approach only works when all elements are positive(>0), it doeasn't work with 
 * negative numbers. We have a solution using map which works on positive as well as negative numbers.
 * Solution is there on my leet code solution in leetcode 30 days  challenge */

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

template<size_t N>
void  PrintSumOfSubArrays(int (&arr)[N], int k)
{
  if (k > N ) {
     return;
  }

  int i = 0, sum = 0;
  // find sum of first window of k size
  for(i = 0; i < k; i++) {
     sum += arr[i];
  }

  for(i = k; i < N; i++) {
     cout<<sum<<" ";
     sum = sum - arr[i-k] + arr[i];
  }
  cout<<sum<<" "<<endl;
}

int main()
{
  int arr[8] = { 1, 2, 4, 3, 7, 8, 2, 5 };
  int k = 3;
  PrintSumOfSubArrays(arr, k);
  return 0;
}
