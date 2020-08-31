/* Given a sorted list of integers, square the elements and give the output in sorted order.
 *
 * For example, given [-9, -2, 0, 2, 3], return [0, 4, 4, 9, 81].
 */

/* Simple solution is to first convert each array elements into its square and than apply any “O(nlogn)” sorting algorithm to sort the array elements.
 */

/* Efficient solution is based on the fact that given array is already sorted. We do following two steps.
 *
 * Divide the array into two part “Negative and positive “.
 * Use merge function to merge two sorted arrays into a single sorted arr
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<size_t N>
void SquareInSortedOrder(int (&arr) [N])
{
  if(N == 0) {
    return;
  }
 
  // find the index starting with positive number
  int k = 0;
  for(k = 0; k < N; k++) {
     if(arr[k] >= 0) {
        break;
     }
  }

  int neg_idx = k-1;
  int pos_idx = k;

  int tmp[N];
  int i = 0;
  while(neg_idx >= 0 && pos_idx < N) {
    if(arr[neg_idx]*arr[neg_idx] <= arr[pos_idx]*arr[pos_idx]) {
       tmp[i++] = arr[neg_idx]*arr[neg_idx];
       neg_idx--;
    } else if (arr[neg_idx]*arr[neg_idx] > arr[pos_idx]*arr[pos_idx]) {
       tmp[i++] = arr[pos_idx]*arr[pos_idx];
       pos_idx++;
    }
  }

   // check for rest elements
   if(neg_idx >= 0) {
     tmp[i++] = arr[neg_idx]*arr[neg_idx];
     neg_idx--;
   }

   if(pos_idx < N) {
     tmp[i++] = arr[pos_idx]*arr[pos_idx];
     pos_idx++;
   }

   // copy the sorted array
   for(int i = 0; i < N; i++) {
      arr[i] = tmp[i];
   }
}
 
int main()
{
   int arr[5] = { -9, -2, 0, 2, 3 };
   SquareInSortedOrder(arr);
   // print the arr
   for(int i = 0; i < 5; i++) {
      cout<<arr[i]<< " ";
   }
   cout<<endl;
   return 0;
}
