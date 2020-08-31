/************ Find inorder successor of any given node in BST ***********************/

/* Note : This prob becomes easy if all nodes have a pointer to parent also.
 * If node doesn't have a pointer to parent then it needs to be handled properly if node doesn't have right subtree. We need to have a track for grand_parent also for this case. Apart of this we require information as we have
 * come from right or left in node traversal.
 *
 *The below solution implements the same. Time complexity - O(logn)
 */

/* Note: This is a iterative solution, recursive solution of this problem is present in this folder: 
 *       bst_inorder_predecessor_successor.c
 *       Recursive solution is really beautiful */


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
   public:
   int data;
   Node* left;
   Node* right;
};

void InsertInBST(Node* root, int data) 
{
   Node* newNode = new Node();
   newNode->data = data;
   newNode->left = NULL;
   newNode->right = NULL;

   bool done = false;
   while(!done) {
      if(root->left == NULL && root->right == NULL){
         if(root->data <= newNode->data) {
            root->right = newNode;
         } else {
            root->left = newNode;
         }
         done = true;
      } else {
         if (root->data <= newNode->data) {
            if (root->right == NULL) {
               root->right = newNode;
               done = true;
            } else {
              root = root->right;
            }
         } else {
            if (root->left == NULL) {
               root->left = newNode;
               done = true;
            } else {
               root = root->left;
            }
         }
      }
   }
}

enum state_e
{
  NONE = -1,
  LEFT,
  RIGHT,
};

int FindInOrderSuccessorUtil(Node* root)
{
  // this util is used when root has right Node
  if(root->right) {
     Node* tmp = root->right;
     while(tmp->left != NULL) {
       tmp = tmp->left;
     }
     return tmp->data;
  }
  return -1;
}

int FindInOrderSuccessor(Node* root, int data)
{
   // if data not found return -1
   if (root == NULL) {
      return -1;
   }

   if(root->data == data) {
     return -1;
   }
   int state = NONE;
   Node* parent = NULL;
   Node* grand_parent = NULL;
   bool found = false;
   while(root) {
      if ( data < root->data ) {
         state = LEFT;
         if(parent) {
            grand_parent = parent;
         }
         parent = root;
         root = root->left;
      } else if (data > root->data) {
         if(parent) {
            grand_parent = parent;
         }
         parent = root;
         state = RIGHT;
         root = root->right;
      } else if (root->data == data) {
         found = true;
         // corner case for max (right most element)
         if((root->right == NULL) && (state == RIGHT) && (grand_parent->data < root->data)) {
            return -1;
         }
         if (root->right != NULL) {
            return FindInOrderSuccessorUtil(root);
         } else {
            if(state == LEFT) {
               return parent->data;
            } else if(state == RIGHT) {
               return grand_parent->data;
            }
         }  
         break;
      }
   } 

   return -1;
}

void PrintInOrder(Node* root) {
   if(root == NULL) {
      return;
   }
   PrintInOrder(root->left);
   cout<<root->data<<endl;
   PrintInOrder(root->right);
}

void PrintLevelOrder(Node* root) {
   queue<Node*> que;
   que.push(root);
   que.push(NULL);
   int level = 1;
   cout<<"level "<<level<<" elements: "<<endl;
   while(!que.empty()) {
      Node* cur = que.front();
      que.pop();
      if(cur == NULL) {
         level++;
         if(!que.empty()) {
           que.push(NULL);
           cout<<"level "<<level<<" elements: "<<endl;
         }
      } else {
        cout << cur->data<<endl;
        if(cur->left) {
           que.push(cur->left);
        }
        if(cur->right) {
           que.push(cur->right);
        }
     }
  }
}

int main()
{
   Node* root = new Node;
   root->data = 20;
   root->left = NULL;
   root->right = NULL;

   // Create BST on root
   InsertInBST(root, 30);
   InsertInBST(root, 40);
   InsertInBST(root, 25);
   InsertInBST(root, 22);
   InsertInBST(root, 10);
   InsertInBST(root, 15);
   InsertInBST(root, 5);

   cout<<"Inorder of given BST is: "<<endl;
   PrintInOrder(root);
   cout<<"Level order of given BST is: "<<endl;
   PrintLevelOrder(root);

   //int data = 15;
   //int data = 5;
   //int data = 22;
   //int data = 10;
   //int data = 25;
   int data = 40;
   int ios = FindInOrderSuccessor(root, data);
   if(ios != -1) {
      cout<<"Inorder successor of data "<<data<<" is: "<<ios<<endl;
   } else {
      cout<<"Inorder successor of data "<<data<<" is not found."<<endl;
   }
   
   return 0;
}
