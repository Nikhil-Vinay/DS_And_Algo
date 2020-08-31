/************* Print Level Order Traversal Of A Tree *******************/
/* Example: 
 *            5
 *          /   \
 *         4     2
 *        / \
 *       4   4
 *
 *  Level Order Traversal - 5, 4, 2, 4, 4
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

void PrintLevelOrder(Node* root)
{
   if (root == NULL) {
      return;
   }
   queue<Node*> node_que;
   node_que.push(root);

   while(!node_que.empty()) {
      Node* node = node_que.front();
      cout<<node->data<<" "<<endl;
      node_que.pop();
      if(node->left != NULL) {
         node_que.push(node->left);
      }
      if(node->right != NULL) {
         node_que.push(node->right);
      }
   }
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
  PrintLevelOrder(root);
  return 0;
}
