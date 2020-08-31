/********* PreOrder of a BST is given, construct the BST ***********************/

/* Note: A BST can be constructed with help of preorder or postorder only.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node
{
  public:
  int data;
  Node* left; 
  Node* right;
  Node(int indata):data(indata), left(NULL), right(NULL) { };
};

Node* CreateTree(int* preOrder, int size, int& preOrderIdx, int min, int max)
{
   // base condition
   if(preOrderIdx >= size) {
      return NULL;
   }

   Node* root = NULL;

   if(preOrder[preOrderIdx] >= min && preOrder[preOrderIdx] <= max) {
      root = new Node(preOrder[preOrderIdx]);
      int leftmax = preOrder[preOrderIdx];
      int rightmin = preOrder[preOrderIdx];
      root->left = CreateTree(preOrder, size, ++preOrderIdx, min, leftmax);
      root->right = CreateTree(preOrder, size, ++preOrderIdx, rightmin, max);
   } else {
     --preOrderIdx; // this is very important, if root is going null, we need to decrease the increased
                    // preOrderIdx for right subtree of calling node, else two time increment will happen
                    // and this will end up with missing one node.  
   }

   return root;
}

void PrintInOrder(Node* root)
{
  if(root == NULL){
    return ;
  }

  PrintInOrder(root->left);
  cout<<root->data<<endl;
  PrintInOrder(root->right);
}

void PrintPostOrder(Node* root)
{
  if(root == NULL){
    return ;
  }

  PrintPostOrder(root->left);
  PrintPostOrder(root->right);
  cout<<root->data<<endl;
}

int main()
{
  int preOrder[7] = { 5, 3, 1, 4, 7, 6, 8};
  int preOrderIdx = 0;
  Node* root = CreateTree(preOrder, sizeof(preOrder)/sizeof(preOrder[0]), preOrderIdx, 0, 99); 
  cout<<"Printing InOrder: "<<endl;
  PrintInOrder(root);
  cout<<"Printing PostOrder: "<<endl;
  PrintPostOrder(root);

  return 0;
}
