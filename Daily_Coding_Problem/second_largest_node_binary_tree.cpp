/************** Second largest node in binary tree *****************************/

/**** Asked by DropBox *********/

/* Given the root to a binary search tree, find the second largest node in the tree */

/** Note: If tree is BST then inorder gives the sorted order, we can find easily largest and second largest with
 * some trick..
 * But here tree is random. It's not BST so the below solution takes O(n) time where n is number of nodes.
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

pair<int, int> SecondLargestNode(Node* root)
{
  if(root == NULL) {
     return pair<int, int> (INT_MIN, INT_MIN);
  }

  // Find largest and second largest on left subtree
  pair<int, int> left = SecondLargestNode(root->left);
  // Find largest and second largest on right subtree
  pair<int, int> right = SecondLargestNode(root->right);

  int largest = INT_MIN, second_largest = INT_MIN;
  if (left.first > left.second) {
     largest = left.first; 
     second_largest = left.second;
  } else {
     largest = left.second; 
     second_largest = left.first;
  }

  if(right.first > largest && right.first > second_largest) {
     second_largest = largest;
     largest = right.first;
  } else if (right.first > second_largest) {
    second_largest = right.first;
  }
 
  if(right.second > largest && right.second > second_largest) {
     second_largest = largest;
     largest = right.second;
  } else if (right.second > second_largest) {
    second_largest = right.second;
  }

   // comapare with root->data
   if(root->data > largest && root->data > second_largest) {
      second_largest = largest;
      largest = root->data;
   } else if (root->data > second_largest) {
     second_largest = root->data;
   }

   return pair<int, int> (largest, second_largest);
}

int main()
{
  // Create Tree
  Node* root = new Node(1);
  AddNode(root, new Node(2), 1, LEFT);
  AddNode(root, new Node(3), 1, RIGHT);
  AddNode(root, new Node(4), 2, LEFT);
  AddNode(root, new Node(6), 2, RIGHT);
  AddNode(root, new Node(5), 3, LEFT);
  // Print preOrder
  PrintPreOrder(root);

  // Find largest and second largest
  pair<int, int> ans = SecondLargestNode(root);
  cout<<"Largest node is: "<<ans.first<<endl;
  cout<<"Second largest node is: "<<ans.second<<endl;

  return 0;
}
