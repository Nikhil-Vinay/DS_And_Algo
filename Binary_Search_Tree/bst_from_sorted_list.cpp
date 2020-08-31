/************* Create BST From Sorted Singly Linked List ***************************/

/* Note: When List Count is even, make (ist_count)/2 th index as root to distribute properly.
 *       1 -> 2 -> 3 -> 4 -> 5 -> 6
 *
 *                    4
 *                /       \
 *               2         5
 *            /    \        \
 *          1        3       6
 *
 *  If we'll make 3 as root here, then BST will not be properly distributed.
 *  In case of odd number of list count also, (list_count)/2th index as root will work.
 */
/* Note: We are solving as first finding the middle node, assigning it as root then calling the API recursively
 * on left subtree and right subtree.
 * 1. If list will be doubly linked list then it would be comparatively easy as when we pass subtree then we can
 *    pass the exact unused left part of list (because we can traverse back). Here as left subtree from start to
 *    middle element(used as root). We need some additional check for this in case of singly linked list.
 *
 * 2. We can solve this problem in same way if we get an sorted array. Solution with array will be very easy 
 *    because we can access every element directly by index.
 *
 * 3. Time complexity for this solution is O(nlogn) because every devided logn call needs to traverse within for
 *    n times to find middle element.
 *
 * 4. If input will be sorted array then, time complexity will be O(logn) because we don't need to iterate for
 *    finding middle element in each iteration.
 */

/* The below solution is based on the above explained idea with O(nlogn) time complexity.
 * We can solve it in O(n) time complexity:
 * 1. Find the middle element of the list to make root of BST. // O(n)
 * 2. Create left subtree iteratively  // O(n/2)
 * 3. Create right subtree iteratively // O(n/2)
 * 4. Total time complexity ~ O(n) + O(n/2) + o(n/2) ~ O(n)
 */     

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class TreeNode 
{
  public:
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int in_data): data(in_data), left(NULL), right(NULL) { };
};

class ListNode
{
  public:
  int data;
  ListNode* next;
  
  ListNode(int in_data):data(in_data), next(NULL) { };
};

TreeNode* MakeBST(ListNode* list, ListNode* first, ListNode* start, ListNode* end)
{
   if(list == NULL) {
      cout<<"returning null"<<endl;
      return NULL;
   }

   TreeNode* new_node = NULL;

   ListNode *start_node = NULL;
   // start_node is always correct as we call recursively by start->next
   // we need to find 
   // find out start_node and end_node in the range which is not used as of now
   if(start == first) {
      start_node = start;
   } else {
     start_node = start->next;
   }

   if(start_node == end){  // no node in the range
      return NULL;
   } else if (start_node->next == end) {  // single node
      new_node = new TreeNode(start_node->data);
      return new_node;     
   } else if(start_node->next->next == end) { // two nodes
      new_node = new TreeNode(start_node->data);
      new_node->right = new TreeNode(start_node->next->data);
      return new_node;
   }
   // find middle node
   ListNode *middle = start_node, *last = start_node;
   while(last != end && (last && last->next != end)) {
      middle = middle->next;
      last = last->next->next;
   }
   new_node = new TreeNode(middle->data);
   new_node->left = MakeBST(list, first, start_node, middle);
   new_node->right = MakeBST(list, first, middle, end);
   return new_node;
}

void AddList(ListNode* &list, int data)
{
  // This API will append node in begining
  ListNode* new_node = new ListNode(data);
  if(list == NULL) {
     list = new_node;
     return;
  }

  new_node->next = list;
  list = new_node;
  return; 
}

void PrintList(ListNode* list){
  while(list) {
    cout<<list->data<<endl;
    list = list->next;
  }
  return;
}

void InOrder(TreeNode* root) {
  if(root == NULL) {
    return;
  }

  InOrder(root->left);
  cout<<root->data<<endl;
  InOrder(root->right);
  
  return;
}

int main()
{
  ListNode* list = NULL;
  AddList(list, 6); 
  AddList(list, 5); 
  AddList(list, 4); 
  AddList(list, 3); 
  AddList(list, 2); 
  AddList(list, 1); 

  cout<<"Printing the sorted list: "<<endl;
  PrintList(list);
  cout<<"Converting into BST"<<endl;
  TreeNode* root = MakeBST(list, list, list, NULL);
  cout<<"Printing InOrder of tree: "<<endl;
  InOrder(root);  
  cout<<"Root Data is: "<<root->data<<endl; 
  return 0;
}
