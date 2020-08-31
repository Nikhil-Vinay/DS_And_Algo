/******* Find max sum contiguous sub array (Cadens Algorithm) ****************/

/** If one array is given , find max sum of contigiuous element subarray in the given array
 * Array = [1 ,5, -4, 2, -10, 10] = max sum of subarray = 10 [10]
 *
 * Cadens algo - It says, keep adding the elements till sum doesnn't go negative and updated max sum at each
 * index. Once you get total sum negative, have updated max sum at that index and start with zero total sum
 * from next element.
 * Logic: You have so far max sum at each index so till you have total sum positive why not keep adding the 
 * elements to total sum and check with max sum because you have hope as may be total sum will exceed the 
 * max sum and you get a new max sum of subarray till total sum is positive.
 * Once total sum goes negative, drop execution here because it will decrease total sum with next positive 
 * elements and start with total sum zero from next index element and keep updating max sum so far.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int MaxSubArraySum (int* arr, int n)
{
  int max_sum = 0;
  int tot_sum = 0;
  for (int i = 0; i < n; i++) {
       if (tot_sum + arr[i] >= 0) {
           if (tot_sum + arr[i] > max_sum) {
               max_sum = tot_sum + arr[i];
           }
       } else {
         tot_sum = 0;
       }   
  }
  return max_sum;
}

int main()
{
  int arr[6] = {1 ,5, -4, 2, -10, 10};
  cout<<"Maximum subarray sum is: "<<MaxSubArraySum(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
  return 0;
}
