/*********** Max Sum Non Adjuscent Sub Array ********************/

/** Given a list of integers, write a function that retirnd the largest sum of non-adjacent numbers. Numbers
 * can be negative or zero. For example :
 * Array - [2, 4, 6, 2, 5] should return 13 [2, 6, 5]
 * Array - [5, 1, 1, 5] should return 10 [5, 5]
 */

/* This is a problem based on dynamic problem, it can be solved with time complexity - O(n). 
 * A very famous approach is applied for this problem, called - inclusion/exclusion.
 * At every index of array, we include and exclude that index ilement and populate max sum till that index by
 * including that index element and excluding that index element.
 *
 * incl_sum at i = sum with including element at index i = max sum at i-2 with including element at i-2 +
 *                                                         element at i
 * excl_sum at i = sum with excluding element at index i
 *
 * Note: max sum at index x by including element x, doesn't mean that element at index x is included, 
 * it is checked whether sum increases by including element at x or not. If sum increases then only element 
 * is added.
 *
 * But, max sum at index x by excluding element x, perfectly means that max sum at index x by excluding
 * element at index x.
 *
 * */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int GetmaxNonAdjucentSum(int* arr, int size)
{
  vector<int> max_incl_sum(size, 0);
  vector<int> max_excl_sum (size, 0);

  for (int i = 0; i < size; i++) {
      // inclusion sum
      if(i >= 1) {
         if ((arr[i] + max_excl_sum[i-1]) > max_incl_sum[i-1]) {
             max_incl_sum[i] = arr[i] + max_excl_sum[i-1];
         } else {
            max_incl_sum[i] = max_incl_sum[i-1];   //this is the trick
         }

      } else {
         max_incl_sum[i] = arr[i];
      }
      // exclusion sum
      if (i >= 1) {
          max_excl_sum[i] = max_incl_sum[i-1];
      } else {
         max_excl_sum[i] = 0;  
      }
  }
  return max(max_incl_sum[size-1], max_excl_sum[size-1]);
}

int main()
{
  int arr1[5] = {2, 4, 6, 2, 5};    
  int arr2[4] = {5, 1, 1, 5};

  cout<<"Max array sum is = "<<GetmaxNonAdjucentSum(arr1, sizeof(arr1)/sizeof(arr1[0]))<<endl;
  cout<<"Max array sum is = "<<GetmaxNonAdjucentSum(arr2, sizeof(arr2)/sizeof(arr2[0]))<<endl;
  return 0;
}

