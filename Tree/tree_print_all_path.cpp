/************* Print all paths fromm root to leaf node *******************/
/* Example: 
 *            5
 *          /   \
 *         4     2
 *        / \
 *       4   4
 *
 *  Paths: [5, 4, 4], [5, 4, 4], [5, 2]
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

void PrintAllPaths(Node* root, int (&path)[100], int index)
{
  if((root->left == NULL) && (root->right == NULL)) {
    cout<<"[ ";
    for(int i = 0; i < index; i++) {
       cout<<path[i]<<" ";
    }
    cout<<root->data<<" ]"<<endl;
    return;
  }
 
  path[index] = root->data;
  PrintAllPaths(root->left, path, index+1);
  PrintAllPaths(root->right, path, index+1);
  return;
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
  int path[100];
  memset(path, 0, sizeof(path));
  PrintAllPaths(root, path, 0);
  return 0;
}
