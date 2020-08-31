/************ Find LCA of a BST *************************/

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

void InsertNodeInBST(Node* &root, int data)
{
  Node* newnode = new Node(data);
  if(root == NULL) {
     root = newnode;
  } else {
    Node* tmproot = root;
    while(true) {
       if(tmproot->data <= data && tmproot->right) {  // duplicate data will go right side
          tmproot = tmproot->right;
       } else if(tmproot->data > data && tmproot->left) {
          tmproot = tmproot->left;
       } else if(tmproot->data <= data) {
          tmproot->right = newnode;
          break;
       } else if(tmproot->data > data) {
          tmproot->left = newnode;
          break;
       }
    }
  }
}

void PrintPreOrder(Node* root)
{
  if(root == NULL) {
     return;
  }
  cout<<root->data<<endl;
  PrintPreOrder(root->left);
  PrintPreOrder(root->right);
}

int LCA(Node* root, int node1, int node2) {   // if node1 and node2 is existing node
   if(root == NULL) {
      return -1;
   }
   
   if(node1 < root->data && node2 < root->data) {
      return LCA(root->left, node1, node2);
   } else if( node1 >= root->data && node2 >= root->data) {
      return LCA(root->right, node1, node2);
   } else if((node1 < root->data && node2 > root->data) ||
             (node1 > root->data && node2 < root->data)) {
      return root->data;
   }
}

int main()
{
  Node* root = NULL;
  InsertNodeInBST(root, 5);
  InsertNodeInBST(root, 7);
  InsertNodeInBST(root, 6);
  InsertNodeInBST(root, 8);
  InsertNodeInBST(root, 3);
  InsertNodeInBST(root, 1);
  InsertNodeInBST(root, 4);
  InsertNodeInBST(root, 10);
  cout<<"PreOrder Is: "<<endl;
  PrintPreOrder(root);
  cout<< "LCA of 6 and 10 is: "<<LCA(root, 6, 10)<<endl;
  return 0;
}
