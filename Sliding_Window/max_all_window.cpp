/* There is a given array of size n and a given window of size k.   0 <= K <= n
 * Find max element in all windows of array.
 */

/* This is a very good example of using sliding window with deque */

/* Note: Think closely, we can't use heap here to store all elements of window because once we will remove the 
 * max element from window, it can be max element of next window.
 */

/* Method-1: Most trivial solution: check in each window. Time complexity: O(NK).
 *
 * Method-2: Using balanced BST of size K. After each wincodw slide, delete first element of previous window and 
 * insert new element of current window. Time complexity: O(NlogK)
 *
 * Method-3: Using dequeue. This is the most efficient solution which is discussed here. Time complexity : O(N).
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<size_t N>
void PrintMaxOfWindow(int (&arr)[N], int k)
{
   deque<int> deq;  // we are storing index of array in this deque.
   int i = 0;

   // find max of first window of length k
   for(i = 0; i < k; i++) {
      // keep deque always in descending order, max will be front of deque and min will be back of deque.
      while(!deq.empty() && arr[i] > arr[deq.back()]){
          deq.pop_back();
      }
      deq.push_back(i);
   }

   while(i < N) {
      // print max value of current window
      cout<< arr[deq.front()] << " ";
      // keep deque always in descending order, max will be front of deque and min will be back of deque.

      // delete all elements from back of deque which is smaller than current value
      // so deque back will always contain index of min of current window

      while(!deq.empty() && arr[i] > arr[deq.back()]) {   // deq.front() = deq[0]
          deq.pop_back();
      }

      // Remove the element which is not part of the window
      while(!deq.empty() && deq.front() < (i-k+1)){
          deq.pop_front();
      }
      deq.push_back(i);
      i++;
   }
   // print max of last window
   cout<<arr[deq.front()]<<endl;

   // Note: By looking a while loop nested in another while loop, it seems time complexity is O(N^2)
   // But look closely, one element will be inserted once and delete once in deque at max. so, inner while
   // loop will have total N iteration collectively from starting to end.
   // So, total time complexity = time complexity of outer loop + time complexity of inner loop
   //                           = O(N) + O(N) ~ O(N)
}

int main()
{
   //int arr[8] = { 5, 3, 15, 2, 10, 20, 25, 10 };
   int arr[4] = { 30, 20, 5, 10 };
   int k = 2;
   PrintMaxOfWindow(arr, k);
   return 0;
}
