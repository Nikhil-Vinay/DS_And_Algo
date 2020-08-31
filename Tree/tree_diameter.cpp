/************* Find length of diameter of a tree *******************/

/** Diameter length of a tree ia max length between two leaf nodes of a tree ****/

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

bool AddNode(Node* root, Node* new_node, int parent_node_data, int new_node_loc)
{
   if(root == NULL){
     return false;
   }
   if(root->data == parent_node_data) {  // we need to attach new_node here
     switch(new_node_loc) {
        case LEFT:
                 {
                   if(root->left == NULL ) {
                      root->left = new_node;
                   } else {
                     cout<<"Left of node wit data "<<parent_node_data<<" is not null"<<endl;
                   }
                 }
                 break;
        case RIGHT:
                 {
                   if(root->right == NULL ) {
                      root->right = new_node;
                   } else {
                     cout<<"Right of node wit data "<<parent_node_data<<" is not null"<<endl;
                   }
                 }
                 break;
        default:
                 cout<<"Child location is not correct for "<<parent_node_data<<endl; 
                 break;
     }
     return true;
   }
  
   bool isAdded = AddNode(root->left, new_node, parent_node_data, new_node_loc);
   if(isAdded == false) {
      isAdded = AddNode(root->right, new_node, parent_node_data, new_node_loc);
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
/************* Diameter ******************/

int GetDiameter(Node* root, int &diameter)
{
  if (root == NULL) {
    return 0;
  }

  int left_depth = GetDiameter(root->left, diameter);
  int right_depth = GetDiameter(root->right, diameter);
  if( diameter < (left_depth + right_depth)) {
      diameter = (left_depth + right_depth + 1);
  }

  return max(left_depth, right_depth) + 1;
}

/*****************************************/

int main()
{
  // Create Tree
  Node* root = new Node(1);
  AddNode(root, new Node(2), 1, LEFT);
  AddNode(root, new Node(3), 1, RIGHT);
  AddNode(root, new Node(4), 2, LEFT);
  AddNode(root, new Node(5), 2, RIGHT);
  AddNode(root, new Node(6), 4, LEFT);
  AddNode(root, new Node(7), 4, RIGHT);
  AddNode(root, new Node(8), 5, LEFT);
  AddNode(root, new Node(9), 5, RIGHT);
  AddNode(root, new Node(10), 8, RIGHT);
  // Print preOrder
  cout<<"PreOrder Of Tree Is: "<<endl;
  PrintPreOrder(root);
  int diameter = 0;
  GetDiameter(root, diameter);
  cout<<"Diameter of tree is: "<<diameter<<endl;
  return 0;
}
