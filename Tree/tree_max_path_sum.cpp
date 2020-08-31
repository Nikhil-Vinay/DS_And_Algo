/* Given a binary tree of integers, find the maximum path sum between two nodes. The path must go through at least one node, and does not need to go through the root.*/

/* Example: 
 *            5
 *          /   \
 *         4     2
 *        / \
 *       4   4
 *
 *  max path sum = 15(4 + 4 + 5 + 2)
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

bool AddNode(Node* root, Node* new_node, Node* parent_node, int new_node_loc)
{
   if(root == NULL){
     return false;
   }
   if(root == parent_node) {  // we need to attach new_node here
     switch(new_node_loc) {
        case LEFT:
                 {
                   if(root->left == NULL ) {
                      root->left = new_node;
                   } else {
                     cout<<"Left of node wit data "<<parent_node->data<<" is not null"<<endl;
                   }
                 }
                 break;
        case RIGHT:
                 {
                   if(root->right == NULL ) {
                      root->right = new_node;
                   } else {
                     cout<<"Right of node wit data "<<parent_node->data<<" is not null"<<endl;
                   }
                 }
                 break;
        default:
                 cout<<"Child location is not correct for "<<parent_node->data<<endl; 
                 break;
     }
     return true;
   }
  
   bool isAdded = AddNode(root->left, new_node, parent_node, new_node_loc);
   if(isAdded == false) {
      isAdded = AddNode(root->right, new_node, parent_node, new_node_loc);
   }

   return isAdded;  
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

int inner_max = 0;

int MaxPathSum(Node* root)
{
   if(root == NULL) {
     return 0;
   }

   int left_sum = 0;
   int right_sum = 0;
   left_sum = MaxPathSum(root->left);
   right_sum = MaxPathSum(root->right);

   if ((left_sum + right_sum + root->data) > inner_max) {
      inner_max = left_sum + right_sum + root->data;
   }

   return max(left_sum, right_sum) + root->data;
}

int main()
{
  // Create Tree
  Node* root = new Node(5);
  Node* childNode1 = new Node(4);
  AddNode(root, childNode1, root, LEFT);
  Node* childNode2 = new Node(2);
  AddNode(root, childNode2, root, RIGHT);
  Node* childNode3 = new Node(4);
  AddNode(root, childNode3, childNode1, LEFT);
  Node* childNode4 = new Node(4);
  AddNode(root, childNode4, childNode1, RIGHT);
  // Print preOrder
  PrintPreOrder(root);
  // Print MaxPathSum
  cout<<"Max Path Sum Is: "<<max(inner_max, MaxPathSum(root))<<endl;
  return 0;
}
