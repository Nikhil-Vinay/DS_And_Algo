// Check if an array can be equally devided or not
// Based on inclusion-exclusion principle
//
// Note: Similar question: Check if any subsequence is available which adds up to a given sum.
//
// Another Important question: If an array's elements needs to be devided in two subsequences then what could
// be the minimum differences between two subsequences.
// Sol for Top-Down apparoach: Solve problem for total_sum/2 to minimize the difference.
// Keep a global variable diff and keep updating min/max diff for each iteration.
//                             
// Sol for bottom-up approach: Solve problem for total_sum/2 to minimize the difference.
// Its a 2-D DP problem. column count is [1...sum] and row count is array elements.
// After populating the 2-D array keep checking for true in bottom row. MOve from right to left, wherever you 
// find a true, that column representing value is min difference.
//

#include<iostream>
using namespace std;

template <typename T, std::size_t sz>
std::size_t size(T (&) [sz])
{
  return sz;
}

int GetArrSum(int *arr, int len)
{
  int val = 0;
  for(int i = 0; i < len; i++)
    val += arr[i];

  return val;
}

bool IsOdd(int val)
{
  return (val&1);
}

bool CheckIfPossible(int *arr, int val, int index)  // 2-D DP
{
  // boundary condition
  if(index < 0)
     return false;

  if (val == 0) {
     return true;
  }

  // apply DP here

  if(arr[index] > val)
     return CheckIfPossible(arr, val, index-1);

   return (CheckIfPossible(arr, val-arr[index], index-1) || CheckIfPossible(arr, val, index-1));
}

int main()
{
  int arr[5] = { 1, 3, 2, 3, 7 };
  int totalVal = GetArrSum(arr, size(arr));
  if(!IsOdd(totalVal))
  {
    bool isPossible = CheckIfPossible(arr, totalVal/2, size(arr)-1);
    if(isPossible)
    {
      cout<<" Equal division is possible"<<endl;
    }
    else
    {
      cout<<" Equal division is not possible"<<endl;
    }
  }
  else
  {
    cout<<" Equal division is not possible"<<endl;
  }
  return 0;
}
