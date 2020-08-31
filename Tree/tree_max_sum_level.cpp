/* Given a binary tree, return the level of the tree with minimum sum. */

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

void PrintMaxSumLevel(Node* root)
{
   if(root == NULL) {
     return;
   }
   queue<Node*> nodeque;

   nodeque.push(root);
   nodeque.push(NULL);

   int level = 0;
   int sum = 0;
   int maxsum = 0;
   int maxsumlevel = 0;

      cout<<nodeque.size()<<endl;
   while(!nodeque.empty()){
      Node* tmp = nodeque.front();
      if(tmp == NULL) {
         nodeque.pop();
         if(sum > maxsum) {
            maxsum = sum;
            maxsumlevel = level;
         }
         sum = 0;
         level += 1;
      } else {
         sum += tmp->data;
         nodeque.pop();
         if(tmp->left) {
            nodeque.push(tmp->left);
         }
         if(tmp->right) {
            nodeque.push(tmp->right);
         }
         if(nodeque.front() == NULL) {
            nodeque.push(NULL);
         } 
      }
   }
   cout<<"Max sum is "<<maxsum<<" at level "<<maxsumlevel<<endl;
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
  //PrintPreOrder(root);
  // Print MaxSumLevel
  PrintMaxSumLevel(root);
  return 0;
}
