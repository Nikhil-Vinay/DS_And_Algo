/*** There is an given array, performs update on the array to update value at any index and perform query to
 * get sum between different intervals of the array **/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// time complexity of building segment tree = O(2*n-1) = O(n)
void buildTree(int* arr, int* tree, int index, int start, int end)
{
   if(start == end) {
      tree[index] = arr[start];
      return;
   }
   
   int mid = (start + end)/2;
   
   buildTree(arr, tree, (2*index + 1), start, mid);  // build left child
   buildTree(arr, tree, (2*index + 2), mid+1, end);  // build right child

   tree[index] = tree[2*index+1] + tree[2*index+2];
 
}

// time complexity of update in segment tree = O(logn)
void updateTree(int* arr, int* tree, int index, int start, int end, int update_idx, int update_val)
{
   if (start == end && start == update_idx) {
      tree[index] = update_val;
      arr[start] = update_val;
      return;
   }

   int mid = (start + end)/2;
   // update exist in left side
   if (update_idx <= mid) {
      updateTree(arr, tree, (2*index+1), start, mid, update_idx, update_val);
   } else if (update_idx > mid) { // update exist in right side
      updateTree(arr, tree, (2*index+2), mid+1, end, update_idx, update_val);
   } else { // update needs to traverse both sides
      updateTree(arr, tree, (2*index+1), start, mid, update_idx, update_val);
      updateTree(arr, tree, (2*index+2), mid+1, end, update_idx, update_val);
   }

   tree[index] = tree[2*index+1] + tree[2*index+2];
}

void printTree(int* tree, int n) 
{
  cout<<"printing tree"<<endl;
  for(int i = 0; i < n; i++) {
     cout<<tree[i]<<" ";
  }
  cout<<endl;
}

// time complexity of query = worst case both side propagates = O(logn) + O(logn) = O(logn)
int query(int* arr, int*tree, int index, int start, int end, int left_idx, int right_idx)
{
   if (start == end) {
      return tree[index];
   }

   int mid = (start + end)/2;
   
   if(right_idx <= mid) {  // move left side
     return query(arr, tree, (2*index+1), start, mid, left_idx, right_idx);
   }

   if(left_idx > mid) {  // move right side
     return query(arr, tree, (2*index+2), mid+1, end, left_idx, right_idx);
   }    

   int ans1 = query(arr, tree, (2*index+1), start, mid, left_idx, right_idx);
   int ans2 = query(arr, tree, (2*index+2), mid+1, end, left_idx, right_idx);

   return ans1 + ans2; 
}

int main()
{
  int arr[5] = {1, 2, 3, 4, 5};
  int* tree = new int[2*5-1];

  // build segment tree
  buildTree(arr, tree, 0, 0, 4);
  printTree(tree, (2*5-1));

  // update tree
  updateTree(arr, tree, 0, 0, 4, 1, 10); // update index 1 with 10 [1, 10, 3, 4, 5]
  printTree(tree, (2*5-1));

  // query
  int ans = query(arr, tree, 0, 0, 4, 1, 3);  // get sum of all elements from index 1 to index 3
  cout<<"Sum of interval is: "<<ans<<endl;
  return 0;
}
