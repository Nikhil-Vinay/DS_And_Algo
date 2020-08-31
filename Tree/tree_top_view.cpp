/******************* Recursive Pre-Order Tree Traversal *********************/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef struct Node_s
{
  int data;
  struct Node_s* left;
  struct Node_s* right;
}Node;


void TopView(Node* root)
{
   // move once left side down and once right side down

   if (root == NULL) {
     return;
   }
   cout<<root->data<<endl;
   Node* tmp = root;
   // left side
   while(tmp && tmp->left) {
      cout<<tmp->left->data<<endl;
      tmp = tmp->left;
   }
   // right side
   tmp = root;
   while(tmp && tmp->right) {
      cout<<tmp->right->data<<endl;
      tmp = tmp->right;
  }
}

int main()
{
   Node *root = new Node();
   root->data = 1;
   root->left = new Node();
   root->left->data = 2;
   root->right = new Node();
   root->right->data = 3;

   root->left->left = new Node();
   root->left->left->data = 4;
   root->left->left->left = NULL;
   root->left->left->right = NULL;

   root->left->right = new Node();
   root->left->right->data = 5;
   root->left->right->left = NULL;
   root->left->right->right = NULL;

   root->right->left = new Node();
   root->right->left->data = 6;
   root->right->left->left = NULL;
   root->right->left->right = NULL;

   root->right->right = new Node();
   root->right->right->data = 7;
   root->right->right->left = NULL;
   root->right->right->right = NULL;

   root->right->left->left = new Node();
   root->right->left->left->data = 8;
   root->right->left->left->left = NULL;
   root->right->left->left->right = NULL;

   TopView(root);
   
   return 0;
}
