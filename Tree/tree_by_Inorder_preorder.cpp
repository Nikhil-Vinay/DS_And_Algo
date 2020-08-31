/************* InOrder and PreOrder are given, Create the tree  *******************/
/* Note: For creation of tree , inorder is must to have.
 * We can create a tree by Inorder, PreOrder combination or Inorder, PostOrder combination
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

enum child { LEFT, RIGHT };

class Node
{
  public:

  int data;
  Node *left;
  Node *right;
 
  Node(int indata):data(indata), left(NULL), right(NULL) { };

};

Node* CreateTree(int* inOrder, int inorder_start_idx, int inorder_last_idx, int* preOrder, int& preOrderIndex) 
{
   Node* root = NULL;
 
   // Base condition (When we get a leaf Node)
   if((inorder_start_idx > inorder_last_idx) || (inorder_last_idx < inorder_start_idx)){
      return NULL;
   }

   if(inorder_last_idx == inorder_start_idx) {
      root = new Node(preOrder[preOrderIndex]);
      return root;
   }

   // Always preOrder array's first element will give the root node of dealing subtree
   root = new Node(preOrder[preOrderIndex]);
   // find the last index of left subtree
   int left_last_index = 0;
   for(int i = inorder_start_idx; i <= inorder_last_idx; i++) {
       if(inOrder[i] == preOrder[preOrderIndex]){
          left_last_index = i;
          break;
       }
    }
    // populate left subtree
    root->left = CreateTree(inOrder, inorder_start_idx, left_last_index-1, preOrder, ++preOrderIndex);

    // populate right subtree
    root->right = CreateTree(inOrder, left_last_index+1, inorder_last_idx, preOrder, ++preOrderIndex);

    return root;

}

void PrintPreOrder(Node* root)
{
  if(root == NULL) {
    return;
  }
  cout<<root->data<<endl;
  PrintPreOrder(root->left);
  PrintPreOrder(root->right);
  return;
}

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

int main()
{
  int inOrder[7] = { 4, 2, 5, 1, 6, 3, 7 };
  int preOrder[7] = { 1, 2, 4, 5, 3, 6, 7 };
  int preOrderIndex = 0;
  // Create Tree
  Node* root = CreateTree(inOrder, 0, 6, preOrder, preOrderIndex);
  // Print preOrder
  cout<<"PreOrder: "<<endl;
  PrintPreOrder(root);
  cout<<"PostOrder: "<<endl;
  PrintPostOrder(root);
  return 0;
}
