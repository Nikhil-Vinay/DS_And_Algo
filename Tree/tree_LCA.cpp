/************* LCA (Least Common Ancestor) Of A Tree  *******************/

/* A node whose left side a node and right side another node exists, that node is LCA os two nodes */


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

/*************** LCA ******************************/

bool GetLCA(Node* root, int data1, int data2, int& lca_node, bool& found)
{
  if(root == NULL) {
    return false;
  }

  if(found) {
     return false;
  }

  if(root->data == data1 || root->data == data2) {
     return true;
  }

  bool left = GetLCA(root->left, data1, data2, lca_node, found); 
  bool right = GetLCA(root->right, data1, data2, lca_node, found); 

  if(left && right) {
    lca_node = root->data;
    found = true;
  }

  return (left || right);
}

/***************************************************/
int main()
{
  // Create Tree
  Node* root = new Node(1);
  AddNode(root, new Node(2), 1, LEFT);
  AddNode(root, new Node(3), 1, RIGHT);
  AddNode(root, new Node(4), 2, LEFT);
  AddNode(root, new Node(5), 2, RIGHT);
  AddNode(root, new Node(6), 5, RIGHT);
  // Print preOrder
  PrintPreOrder(root);
  // LCA
  int lca_node = 0;
  bool found = false;
  GetLCA(root, 4, 6, lca_node, found);

  if (found) {
    cout<<"LCA of nodes are : "<<lca_node<<endl;
  } else {
    cout<<"LCA node is not found"<<endl;
  }
  return 0;
}
