/************ Find Single Occurence Number (Asked By Google) **************************/

/* Given an array of integers where every integer occurs three times except for one integer, which only occurs 
 * once, find and return the non-duplicated integer.
 *
 * For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.
 *
 * Do this in O(N) time and O(1) space.
 */

/* 1. Sorting solution will take O(nlogn) time.
 * 2. Hashing will take O(n) time but O(n) space. We can use unordered_map.
 * 3. We can solve by storing bit counts of all elements and take modulus by 3. It will also have O(32) space.
 */

/** Note: We will conside the 3rd solution as our best solution as space complexity O(32) is constant so it can 
 * be considered as O(1) spce complexity */

/* We have one another solution as below:
 * Add each number once and multiply the sum by 3, we will get thrice the sum of each element of the array. 
 * Store it as thrice_sum. Subtract the sum of the whole array from the thrice_sum and divide the result by 2. 
 * The number we get is the required number (which appears once in the array).
 *
 * Array [] : [a, a, a, b, b, b, c, c, c, d]
 * Mathematical Equation = ( 3*(a+b+c+d) – (a + a + a + b + b + b + c + c + c + d) ) / 2
 *
 * In more simple words: ( 3*(sum_of_array_without_duplicates) – (sum_of_array) ) / 2
 *
 * We wiil use <set> for having only unique elements.
 */

/** Note(VVI) : Constant space or constant time is always considerd as O(1) time or O(1) space.
 * O(32) is considered as O(1).
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<typename T, size_t N>
T FindUnique(T(&arr)[N])
{
  set<T> myset;    // constant space O(number of unique element) ~ O(1)
  for(int i = 0; i < N; i++) {
    myset.insert(arr[i]);   // duplicate elements will be discarded // O(log(k!)), k is number of unique element
  }

  int three_times = accumulate(myset.begin(), myset.end(), 0) * 3;  // accumulate 3rd argument 0 is init val
  int arr_tot_sum = accumulate(arr, arr+N, 0);

  return (three_times - arr_tot_sum)/2;
}

int main()
{
  int arr[7] = {6, 1, 3, 3, 3, 6, 6};
  cout<<FindUnique(arr)<<endl;
  return 0;
}
