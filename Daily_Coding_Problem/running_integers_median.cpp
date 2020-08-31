/****************** Display median of a running integer sequence stream **********************/

/* Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out the median
 * of the list so far on each new element.Recall that the median of an even-numbered list is the average of the 
 * two middle numbers of sorted-list and median of an odd-numbered list is the middle element of sorted-list.
 *
 * For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:
 * 2       // 2
 * 1.5     // 2 1
 * 2       // 2 1 5
 * 3.5     // 2 1 5 7
 * 2       // 2 1 5 7 2
 * 2       // 2 1 5 7 2 0
 * 2       // 2 1 5 7 2 0 5
 * 
 */

/* Note: Time complexity: For each data, maximum two push happen. SO, for each element, O(2logn) ~ O(logn)
 *       For n elements, O(nlogn) but n is dynamic here, everytime n is increasing by 1.
 */       

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

double RunningMedian(int data)
{
   double median = 0.0f;
  
   // we can make these two as global also, we don't need to use static in that case
   static priority_queue<int> max_heap;    // left half
   static priority_queue<int, vector<int>, greater<int> > min_heap;    // right half

   // in case of odd number of data, laways keed left half (max_heap) with one extra element
   // in case of even number of data, both left and right heap will have same number of data

   if(max_heap.size() == 0) {
     max_heap.push(data);
     return max_heap.top();
   } else if (max_heap.size() == min_heap.size()) {
      if(min_heap.top() < data) {
         int x = min_heap.top();
         min_heap.pop();
         min_heap.push(data);
         max_heap.push(x);
      } else {
         max_heap.push(data);
      }
      return max_heap.top();
   } else {
      if(max_heap.top() > data) {
        int x = max_heap.top();
        max_heap.pop();
        max_heap.push(data);
        min_heap.push(x);
      } else {
        min_heap.push(data);
      }
      return ((double)(max_heap.top()) +(double)(min_heap.top()))/2.0f;
   }
}

int main()
{
  int arr[7] = {2, 1, 5, 7, 2, 0, 5};
  for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
     cout<<"Running Median Is: "<<RunningMedian(arr[i])<<endl;
  }
  
  return 0;
}
