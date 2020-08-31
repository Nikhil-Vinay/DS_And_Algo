/************* Find if a tree is valid BST tree *******************/
/* Example: 
 *            6
 *          /   \
 *         4     8
 *        / \
 *       3   5
 *
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

bool IsBST(Node* root) {
   if(root == NULL) {
     return true;
   }

   if(
      (root->left ? (root->left->data < root->data) : true) && 
      (root->right ? (root->right->data > root->data) : true) &&
      IsBST(root->left) && IsBST(root->right)
     ) {
        return true;
     }

     return false;
}

int main()
{
  // Create Tree
  Node* root = new Node(6);
  Node* childNode1 = new Node(4);
  AddNode(root, childNode1, root, LEFT);
  Node* childNode2 = new Node(8);
  AddNode(root, childNode2, root, RIGHT);
  Node* childNode3 = new Node(3);
  AddNode(root, childNode3, childNode1, LEFT);
  Node* childNode4 = new Node(5);
  AddNode(root, childNode4, childNode1, RIGHT);
  // Print preOrder
  if(IsBST(root)) {
    cout<<"Tree is BST"<<endl;
  } else {
    cout<<"Tree is not BST"<<endl;
  }
  return 0;
}
