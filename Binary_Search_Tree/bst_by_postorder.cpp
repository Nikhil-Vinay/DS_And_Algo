/* Create a BST by given post order */
 
/* BST can be created by inorder easily as inorder comes in ascending order but the problem is any node of 
 * inorder can be chosen as root so there could be many ways to construct a BST by inorder. if we choose first
 * element of inorder as root then constructed BST will be ful skewed.
 */
 
/* If post order is given then it is clear that rightmost node is root of BST then start coming backward in the 
 * postorder array and find the first node which is smaller or equal to right most node, this element will be 
 * root of left subtree. 
 * Now split the problem in two and change the indexes properly and pass as recursion for left subtree and
 * right subtree. */

/* Similarly, BST can be constructed by only preorder also. 
 * Better create a BST and get the postorder/preoorder on notebook then do dry run. It helps alot in solving
 * this kind of problems */

#include<iostream>
#include<bits/stdc++.h>
#define METHOD1 0

using namespace std;

class Node
{
   public:
   int data;
   Node* left;
   Node* right;
   Node() : data(0), left(NULL), right(NULL) { }
   Node(int indata, Node* inleft, Node* inright):data(indata), left(inleft), right(inright) { }
};

void PrintPostOrder(Node* root)
{
   if(root == NULL) {
     return;
   }

   PrintPostOrder(root->left);
   PrintPostOrder(root->right);
   cout<<root->data<<endl;
   return;
}

#if METHOD1
/* Method-1, as per explained above, time complexity is O(n^2) becayse of while loop */

template<size_t N>
Node* CreateBST(int (&postOrder)[N], int start, int end)
{
   if(end < start) {
      return NULL;
   }

   // find root node data
   int root_node_data = postOrder[end];

   // create root node
   Node* root = new Node(root_node_data, NULL, NULL);
   // find left subtree root index
   int i = end-1;
   while((i >= start) && (postOrder[i] >= postOrder[end])) {
       i--;
   }

   root->left = CreateBST(postOrder, start, i);
   root->right = CreateBST(postOrder, i+1, end-1);
   
   return root; 
}

#else
/* Method-2, Most efficient one, time complexity O(n) */
template<size_t N>
Node* CreateBST(int (&postOrder)[N], int range_start, int range_end, int &idx)
{
   if (idx < 0) {
      return NULL;
   }

   Node *root = NULL;

   int key = postOrder[idx];
   if ((key > range_start) && (key < range_end)) {
       root = new Node(key, NULL, NULL);
       idx = idx-1;
       // Two things are very importtant here: 
       // 1. pass the idx by reference or pointer.
       // 2. construct first the right subtree then left subtree
       // Every call happens with a root node, we need to construct first right subtree for that root node
       // then, because idx are passed by reference so automatically it will keep on decreasing and will come
       // out from the range for right subtree then it will start constructing the left subtree.
       // It's tricky ...  do dry run.
       if((idx) >= 0) {
          root->right = CreateBST(postOrder, key, range_end, idx);
          root->left = CreateBST(postOrder, range_start, key, idx);
       }
   }
   return root;
}
#endif

int main()
{
   int postOrder[6] = { 1, 7, 5, 50, 40, 10 };
#if METHOD1
   Node* root = CreateBST(postOrder, 0, sizeof(postOrder)/sizeof(postOrder[0]));
#else
   int idx = sizeof(postOrder)/sizeof(postOrder[0]) - 1;
   Node* root = CreateBST(postOrder, -INT_MAX, INT_MAX, idx);
#endif
   PrintPostOrder(root);
   return 0;  
}
