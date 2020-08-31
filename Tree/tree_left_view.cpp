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

void LeftViewUtil(Node* root, int count, set<int> &countset)
{
  if(root == NULL) {
    return;
  }

  if(countset.find(count) == countset.end()) {
    cout<<root->data<<endl;
  }

  countset.insert(count);

  LeftViewUtil(root->left, count+1, countset);
  LeftViewUtil(root->right, count+1, countset);
}

void LeftView(Node* root)
{
   // We need to look into all nodes, traverse by preorder only because we have to look leftside first
   // count at root = 0, increase the count by one if we move down by left or right,
   // Time COmplexity = O(n * logn)
   // We can do it by O(n) by using unordered_set instead of set

   set<int> countset;
   LeftViewUtil(root, 0, countset);
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

   LeftView(root);
   
   return 0;
}
