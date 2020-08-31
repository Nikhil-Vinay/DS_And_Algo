/* Given a binary tree where all nodes are either 0 or 1, prune the tree so that subtrees containing all 0s are removed. */

/* Given Tree:
 *
 *      0
 *     / \
 *    1   0
 *       / \
 *      1   0
 *     / \
 *    0   0
 *
 * Pruned Tree:
 *
 *      0
 *     / \
 *    1   0
 *       /
 *      1
 */     

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
enum ChildLoc
{
   LEFT,
   RIGHT
};

class Node
{
  public:
  int data;
  Node* left;
  Node* right;
  Node():data(0), left(NULL), right(NULL) { }
  Node(int indata):data(indata), left(NULL), right(NULL) {}
  
  void AddNode(int dir, Node* newNode) {
    if(dir == LEFT && left == NULL) {
       left = newNode;
    }

    if(dir == RIGHT && right == NULL) {
       right = newNode;
    }
  }
};

bool PruneZeroTree(Node *root)
{
   if(root == NULL) {
      return true;
   }

   bool left = false;
   bool right = false;
   if(PruneZeroTree(root->left)) {
      left = true;
      if(root->left) {
         delete root->left;
         root->left = NULL;
      }
   }
   if(PruneZeroTree(root->right)) {
      right = true;
      if(root->right) {
         delete root->right;
         root->right = NULL;
      }
   }

   if(left && right && root->data == 0) {
     return true;
   }

   return false;
}

void PrintInOrder(Node *root) {
   if(root == NULL) {
      return;
   }
   PrintInOrder(root->left);
   cout<<root->data<<endl;
   PrintInOrder(root->right);
}

int main()
{
   // create tree
   Node* root = new Node(0);
   root->AddNode(LEFT, new Node(1));
   root->AddNode(RIGHT, new Node(0));
   root->right->AddNode(LEFT, new Node(1));
   root->right->AddNode(RIGHT, new Node(0));
   root->right->left->AddNode(LEFT, new Node(0));
   root->right->left->AddNode(RIGHT, new Node(0));
   cout<<"Pre Prune PreOrder:"<<endl; 
   PrintInOrder(root);
   PruneZeroTree(root); 
   cout<<"Post Prune PreOrder:"<<endl; 
   PrintInOrder(root);
   return 0;
}
