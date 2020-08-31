/************** Find sliding Window Maximum ************************************/
/* Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.
 * Input :
 * arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}
 * k = 3 
 * Output :
 * 3 3 4 5 5 5 6
 *
 * Input :
 * arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}
 * k = 4 
 * Output :
 * 10 10 10 15 15 90 90
 */

/** Method-1 (Brute Force).
 * We will have an outer for loop of 0 to n-1. Then, we'll have a inner for loop for (j = i) to (j = i+k) for 
 * each window. We'll iterate and find maximum in each iteration. Time complexity - O(nk).
 */

/** Method-2 (Using Max Heap).
 * This probe looks very attractimg to get solved by max heap but not truly optimized.
 * We will store first k elements in heap then, will iterate from (i = k) to (i = n)
 * 1. Max of the first k elements will be max of heap
 * 2a. Find the last element of previous window in heap and replace it by first element of next window. (O(K))
 * 2b. Heapify the heap again (O(logK))
 *
 * Total time complexity - O((O(k) + O(logK))*O(n)) ~ O(O(k)*O(n)) ~ O(nk)
 */

/** Method-3 (Using self balanced binary tree, we can use set in C++)
 * Insert first k elements in in self balanced binary tree, will iterate from (i = k) to (i = n)
 * search for max - O(logk)
 * find the last element of previous window and delete it. O(logK)
 * insert the first element of next window. O(logK)
 *
 * Total time complexity - O((O(logk) + O(logk))*O(n)) ~ O(nlogk)
 */

/* Method-4 (Using deque) // This is the most efficient method.
 * We create a Deque, Qi of capacity k, that stores only useful elements of current window of k elements. 
 * An element is useful if it is in current window and is greater than all other elements on left side of it in 
 * current window. We process all array elements one by one and maintain Qi to contain useful elements of current
 * window and these useful elements are maintained in sorted order. The element at front of the Qi is the largest
 * and element at rear of Qi is the smallest of current window. 
 * The below implementationis based on this only.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void printKMax(int arr[], int n, int k) 
{ 
    // Create a Double Ended Queue, Qi that will store indexes of array elements 
    // The queue will store indexes of useful elements in every window and it will 
    // maintain decreasing order of values from front to rear in Qi, i.e., 
    // arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order 
    std::deque<int> Qi(k); 
  
    /* Process first k (or first window) elements of array */
    int i; 
    for (i = 0; i < k; ++i) { 
        // For every element, the previous smaller elements are useless so 
        // remove them from Qi 
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
            Qi.pop_back(); // Remove from rear 
  
        // Add new element at rear of queue 
        Qi.push_back(i); 
    }

    // Process rest of the elements, i.e., from arr[k] to arr[n-1] 
    for (; i < n; ++i) { 
        // The element at the front of the queue is the largest element of 
        // previous window, so print it 
        cout << arr[Qi.front()] << " "; 
  
        // Remove the elements which are out of this window 
        while ((!Qi.empty()) && Qi.front() <= i - k) 
            Qi.pop_front(); // Remove from front of queue 
  
        // Remove all elements smaller than the currently 
        // being added element (remove useless elements) 
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
            Qi.pop_back(); 
  
        // Add current element at the rear of Qi 
        Qi.push_back(i); 
    } 
  
    // Print the maximum element of last window 
    cout << arr[Qi.front()];
    cout<<endl;
}

/* Time Complexity: O(n). It seems more than O(n) at first look. If we take a closer look, we can observe that 
 * every element of array is added and removed at most once. So there are total 2n operations.
 * Auxiliary Space: O(k)
 *
 * It is good example of deque beaty. - push_back(), pop_back(), push_front(), pop_front(), empty(), back(),
 * front().
 *
 * Variant of this question: Find addition of min and max element of a fixed window(k) in an array. Find it for
 * all windows.
 * We need to know the min and max each time from each window. So, here we'll have to have two deque, one for 
 * min and other for max for each window.
 */
 

int main()
{
   int arr[] = { 12, 1, 78, 90, 57, 89, 56 }; 
   int n = sizeof(arr) / sizeof(arr[0]); 
   int k = 3; 
   printKMax(arr, n, k);

   return 0;
}
