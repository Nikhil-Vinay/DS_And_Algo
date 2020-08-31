/* There are two players (A and B) playing game on a binary tree. Player gets the first chance to select a node. Once player A select a node in the tree, player B can select any node in the tree.
Any player selects a node in the tree next time he needs to select only adjascent of the selected node of tree. So, you need to return whether B can win the game or not. Return true or false.

Solution: After careful observation, it is needed as B has to stop A to select the node which has more than half region. If A selects any node, there are three regions left subtree, right subtree and above part of the node selected. Player B needs to count the the nodes of left subtree of selected node, right subtree of selected node and rest of nodes existing in above part of the selected node. If any region has more elements of collective node of rest of the two regions then player B can win.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node
{
   public:
   int data;
   Node* left;
   Node* right;
   Node(int indata) {
      data = indata;
      left = right = NULL;
   }
};

int CountNode(Node* root) 
{
   if(root == NULL) {
      return 0;
   }
   return 1 + CountNode(root->left) + CountNode(root->right);
}

Node* FindNode(Node* root, int x)
{
   if (root == NULL) {
      return NULL;
   }

   if(root->data == x) {
      return root;
   }
   Node* left =  FindNode(root->left, x);
   Node* right = FindNode(root->right, x);

   return (left==NULL)?right:left;
}

bool IsBingBangGameWin(Node* root, int n, int x)  // n = total number of nodes, x = node selected by A
{

   Node* selected_node = FindNode(root, x);

   int left = CountNode(selected_node->left);
   int right = CountNode(selected_node->right);
   int rest = n - (left + right + 1);

   if(left > (right + rest)) {
      return true;
   }
   if(right > (left + rest)) {
      return true;
   }
   if(rest > (left + right)) {
      return true;
   }
   
   return false;
}

int main()
{
   int n, x;  // n = total number of nodes in tree, x = node selected by player A

   return 0;
}

