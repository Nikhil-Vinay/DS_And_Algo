/************* What is heap data structure and what is its use ?
 *
 *  How it is used to get median of running integer sequence **************/


/* In C++ STL, heap is already implemented as priority que.
 * priority_queue <int> pq;   // default it is max heap
 * priority_queue <int, vector<int>, greater<int> > pq;  // mean heap
 *
 * For user defined structure.
 * To compare two points 
   class myComparator 
   { 
      public: 
      int operator() (const Point& p1, const Point& p2) 
      { 
        return p1.getX() > p2.getX();   // for min heap 
      } 
   }

  priority_queue <Point, vector<Point>, myComparator > pq;
  pq.push(Point(10, 2)); 
  pq.push(Point(2, 1));

 */

/* Complete Binary Tree: A complete binary tree is a binary tree in which every level, except possibly the last,
 * is completely filled, and all nodes are as far left as possible.
 *
 * Binary Heap : A Binary Heap is a Complete Binary Tree where items are stored in a special order such that 
 * value in a parent node is greater(or smaller) than the values in its two children nodes. The former is called
 * as max heap and the latter is called min heap. The heap can be represented by binary tree or array.
 * 
 * If parent index is n then, two childre indexes are - (2n+1) & (2n+2).
 *
 * If any binary tree is complete then it can be easily stored as array to make space and accessing efficient.
 *
 * How to build the heap?
 *
   Heapify procedure can be applied to a node only if its children nodes are heapified. So the heapification 
   must be performed in the bottom up order.

   we start heapifying from bottom most parent and comes up till root. Each node heapification takes logN time
   so full array heapification will take O(NlogN) time. Bottom most parent is x
   2x+2 = N ,  x = (N/2)-1

Note: Heapifying one element is top to bottom, O(logN)
      Heapifying an array means , heapifying elements( N/2 -1 to 0 ) in bottom up order and heapifying each
      element in topdown order. Total cost = O(NlogN)

 /********** Heap Sort (Concept of heapify an array and heap sorting) *************************/

 #include <iostream> 
  
using namespace std; 

// Building max heap for ascending order sort. (mean heap for descending order sort).
// Below example for ascending order sort so, building max heap
 
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r;

    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
}

// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--)      // O(NlogN) for heapifying the full array
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--)                // N
    { 
        // Move current root to end 
        swap(arr[0], arr[i]);                 // constant
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0);                   // logN for heapifying single element
    }                                         // total cost of this for loop is O(NlogN)
}                                             // total cost of sorting - O(NlogN) + O(NlogN) ~ O(NlogN)

void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 
  
// Driver program 
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    heapSort(arr, n); 
  
    cout << "Sorted array is \n"; 
    printArray(arr, n); 
}

/********* How to insert an element in a heap *******************************
 *
 * Insert the element in end of array then heapify for this last element in bottom up manner.
 * Total cost of insertion is O(logN) 
 * Only in case of insertion, we go bottom up for heapifying newly inserted element else,
 * in all other case single element is heapified by top down approach only. */

/******** How to delete an element in a heap ********************************
 * find the element index and keep swapping with its parent and come up till root. o(logN)
 * copy last index to root and decrease the array size by 1. 
 * heapify the root element as top down to balance the tree. o(logN)
 * Total cost = o(logN) + o(logN) ~ o(logN)

/*********************** Related problems ***********************************/

/*  k largest(or smallest) elements in an array  
    Sol-1: Sort the array, then get k elements from array end. - O(NlogN)
    Sol-2: Build a heap o(N)  // I know it O(NlogN), don't know it happens, need to check
           delete an elements K times - O(KlogN)
           Total cost = O(N) + O(KlogN).

/*  Sort a nearly sorted (or K sorted) array.
 *  K sorted array means if K = 2 then an element at index i in an array can be at i-2, i-1, i, i+1, i+2.
 *
 *  For sorting a nearly sorted array, insertion sort is a good choice.
 *
 *  We can sort such arrays more efficiently with the help of Heap data structure. Following is the detailed 
 *  process that uses Heap.
 *  1) Create a Min Heap of size k+1 with first k+1 elements. This will take O(k) time (See this GFact)
 *  2) One by one remove min element from heap, put it in result array, and add a new element to heap from 
 *     remaining elements.
 *
 *  Removing an element and adding a new element to min heap will take Logk time. So overall complexity will be O(k) + O((n-k)*logK) 
 *
 *  We can test it using priority_que in c++.   */

