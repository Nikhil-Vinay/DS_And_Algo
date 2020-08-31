/************* Merge K Sorted Array *************************************/

/*** There are k arrays are given and all arays are sorted. We need to create a single sorted array with all 
 * elements.
 *
 * Suppose all arrays are of same lengths(n).
 *
 * Mehod-1:
 *
 * We merge two arrays by merging two sorted array method (time complexity - O(n+n) = o(2n)
 * We merge third array with the combined array of first and second array. (time complexity = O(2n+n) = O(3n))
 * and so on...
 *
 * so total time complexity = O(2n + 3n + 4n......kn) // for k array
 *                          = O(n(2+3....K)) = O(n*k*(k+1)/2) = O(nk^2)
 *
 * Method-2:
 *
 * We collect all elements in a singke array then will sort it out. Time complexity = O(knlogkn)
 *
 * Method-3:
 *
 * We will take advantage of sorted array. We'll have a priority queue(min heap) and will insert k elements(first   elements of all k array). we take the min element out and will insert another element in heap from the array 
 * )where the element comes out from) and so on....always no of elements in priority queue will be same (k).
 *
 * inserting an element in pq will take - logk
 * removing an element from pq will take constant time.
 *
 * So, overall time complexity of this solution will be O(knlogk)  // kn times insertion in pq
 * Here challenge is how to know the popping element from the heap belongs to which array so we could insert
 * next element from that array to heap.
 *
 * Heap can have more that one similar element (x) from different array then we can't which array this popping
 * element comes from. We use a data structure to store the element which contains - element, array_index and
 * element_index. Please look the below solution. It is very interesting.
 *
 */

/* Note: There is another method which can achieve same time complexity as O(knlogk).
 * We can use merge two sorted array methos and sort in pair. Say for example we have k sorted array and will
 * sort in pair as (arr-1, arra-2), (arr-3, arr-4) ....... (array-k-1, array-k)
 * Next time again we will repeat the same so, every time problem will be cut by half and total k arrays are so,    it will take logk time, each iteration of logk will take nk (max) in merging two sorted array so, total time
 * complexity will ne O(nklogk).
 *
 * But previous implementation(using heap) is considered more efficient.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node
{
  public:
  int element;        // element of the array
  int arr_index;      // index of array
  int elm_index;      // index of this element in this array

  Node():element(0), arr_index(0), elm_index(0) { };
  Node(int inelement, int in_arr_index, int in_elm_index):element(inelement),arr_index(in_arr_index), elm_index(in_elm_index) { };
};

//bool my_comparator1(Node& node1, Node& node2) {
//   return (node1.element < node2.element);
//}
//
class my_comparator1
{
  public:
  bool operator()(Node& node1, Node& node2) {
       return (node1.element > node2.element);  // for min heap, greater<type>
  }
};

int* MergeArray(int (&arr)[3][4], int k, int n)
{
  int * finalArr;
  finalArr = new int[k*n];
 
  // default priority queue is max pq
  // priority_queue <int> pq; 
  // we need to create a min pq by overloading comparator and vector type
  // priority_queue <Type, vector<Type>, ComparisonType > min_heap;
  // priority_queue <int, vector<int>, greater<int> > pq; // less<int> for mah pq
  priority_queue <Node, vector<Node>, my_comparator1> pq; // better to have a functor comparator

  for(int i = 0; i < k; i++) {
     Node node(arr[i][0], i, 0);
     pq.push(node);
  }

  // push(element)  -> insert an element
  // top() -> access top element
  // pop() -> remove an element
  // size() -> size of heap
  // empty() -> check if heap is empty
  int i = 0;
  while(i < (n*k)) {
      Node node = pq.top();
      finalArr[i++] = node.element;
      Node next_node;
      pq.pop();  // remove current element
      // insert new node with next element from the array from where element is removed
      if(node.elm_index == n-1) {  // all elements have benn taken from this array
         next_node = Node(INT_MAX, node.arr_index, node.elm_index+1);
      } else {
         next_node = Node(arr[node.arr_index][node.elm_index+1], node.arr_index, node.elm_index+1);
      }
      pq.push(next_node);
  }

  return finalArr; 
}

int main()
{
   int arr[3][4] = { {1, 4, 7, 9},     // k = 3, n = 4
                     {2, 5, 8, 10},
                     {3, 6, 9, 11}};

   int* finalArr = MergeArray(arr, 3, 4); 
   // Printing final array
   int i = 0;
   while(i < (3*4)) {
      cout<<finalArr[i++]<<" ";
   }
   cout<<endl;

   return 0;
}
