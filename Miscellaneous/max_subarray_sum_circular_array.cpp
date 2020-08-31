/* Find max circular sub array sum of a array of positive and negative integers */

/* This problem is upgradation os kadens algorithm of finding max linear subarray sum.
 * There are two cases for this problem's solution.
 * case1: max circular subarray sum could be max linear sum itself [find it by kadens algo]
 * case2: If we connect end of the array with beginning of the array then max circular subarray sum can be 
 * calculated as below:
 *
 * find total_array_sum - (linear subarray sum which is not contributing in circular subarray sum)
 * Note: This linear non contributing subarray sum must be happen in the middle of the array (if circular
 *       subarray sum is evaluated).
 * invert all the elements sign in the array then negative -> positive, positive -> negative
 * calculate max subarray linear sum now, it will be subarray sum of non contributing elements
 * find circular_sub_array_sum = total_array_sum - ( - max_sub_array_sum_of_non_contributing_elem)
 *
 * return max of case1 and case2
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
template<size_t N>
int KadensMaxSubArraySum(int (&arr)[N])
{
   int max_sum_so_far = 0, max_sum = 0;
   for(int i = 0; i < N; i++) {
      max_sum_so_far += arr[i];
      if(max_sum_so_far > max_sum) {
         max_sum = max_sum_so_far;
      }

      if(max_sum_so_far < 0) {
         max_sum_so_far = 0;
      }
   }
   return max_sum;  
}

template<size_t N>
int maxSubArraySumCircularArray(int (&arr)[N])
{
   // case-1: find max subarry sum by kadens rule 
   int kadens_max_sum = KadensMaxSubArraySum(arr);
   
   // case-2: find (total_array_sum) - ( - subarray sum by inverted sign element by kadens rule)
   //              (total_array_sum) + (subarray sum by inverted sign element by kadens rule)
   int total_array_sum = 0;
   for(int i = 0; i < N; i++) {
      total_array_sum += arr[i];
      arr[i] = -arr[i];
   }
   int circular_max_sum = total_array_sum + KadensMaxSubArraySum(arr);

   return (kadens_max_sum > circular_max_sum) ? kadens_max_sum : circular_max_sum;
         
}

int main()
{
   int arr[7] = {1, 5, -6, -7, 8, 9, -3 };
   cout<< "Max sub array sum is: "<<maxSubArraySumCircularArray(arr)<<endl;
   return 0;
}
