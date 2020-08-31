/************* Find number of unival subtree in a tree *******************/
/* Unival subtree is a tree whose all nodes are of same value */
/* Example: 
 *            5
 *          /   \
 *         4     2
 *        / \
 *       4   4
 *
 *  Number of unival subtree is 4
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

/************* Count of unival subtree ***************/

bool GetUnivalSubTree(Node* root, int &count)
{
  // If both child nodes are null
  if(root->left == NULL && root->right == NULL) {
    count = count+1;
    return true;
  }

  // If one child node is null
  if((root->left == NULL) && GetUnivalSubTree(root->right, count)){
    if(root->data == root->right->data) {
      count = count + 1;
    }
    return true;
  }

  if((root->right == NULL) && GetUnivalSubTree(root->left, count)){
    if(root->data == root->left->data) {
      count = count + 1;
    }
    return true;
  } 

  // If both child nodes are not null
  if( GetUnivalSubTree(root->left, count) &&  GetUnivalSubTree(root->right, count) ) {
     if((root->data == root->left->data) && (root->data == root->right->data)) {
        count = count + 1;
     }
     return true;
  }

  return false;
}

/*****************************************************/

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

  int unival_tree_count = 0;
  GetUnivalSubTree(root, unival_tree_count);
  cout<< "Number of unival tree count is: "<<unival_tree_count<<endl;
  return 0;
}
