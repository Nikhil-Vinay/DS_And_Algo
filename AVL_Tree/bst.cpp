/************ Create a binary search tree insert and delete function ************/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class bstree
{
   public:
   int data;
   bstree* left;
   bstree* right; 
};

bstree* CreateTreeNode(int data)
{
  bstree* bst = new bstree();
  bst->data = data;
  bst->left = NULL;
  bst->right = NULL;
}

void InsertData(bstree* root, int data)
{
   // create tmpnode
   bstree* tmpnode = CreateTreeNode(data);
   bstree* tmproot = root;
   int dir = -1;  // unknown
   while(root != NULL)
   {
      if(root->data > tmpnode->data) {
         tmproot = root;
         root = root->left;
         dir = 0;  // left
      } else {
         tmproot = root;
         root = root->right;
         dir = 1;  // right
      }
   }

   if(dir == 0) {
      tmproot->left = tmpnode;
   } else if(dir == 1) {
      tmproot->right = tmpnode;
   } else {
      cout<<"unknown position to insert the node"<<endl;
   }
}

bstree* InOrderSuccesor(bstree* root)
{
   bstree* tmpnode = root;
   tmpnode = tmpnode->right;
   while(tmpnode->left != NULL) {
      tmpnode = tmpnode->left;
   }
   return tmpnode;
}

/* Deletion a node in bst is interesting */
bstree* DeleteNode(bstree* root, int data)
{
    // base condition
    if(root == NULL) {
       return NULL;
    }

    // traverse if right node is not found to delete
    if(root->data > data) {
       root->left = DeleteNode(root->left, data);
    } else if (root->data < data) {
       root->right = DeleteNode(root->right, data);
    }
    // Delete if right node is found to delete
    else if(root->data == data) {
       bstree* tmpnode = NULL;
       int tmpdata;
       // if root has no child
       if(root->left == NULL && root->right == NULL) {
          delete root;
          return NULL;
       }
       // if root has only one child
       if(root->left && root->right == NULL) { 
          tmpnode = root->left;
          delete root;
          return tmpnode;
       }
       if(root->right && root->left == NULL) { 
          tmpnode = root->right;
          delete root;
          return tmpnode;
       }
     // if root has both the children
     // This is tricky, we know bst inorder is always in ascending order so, to keep it in ascending order after
     // deletion of a node, we can tweak with inorder successor or inorder predecessor.
     // We are doing here with help of inorder succesor.
     // Since the root has both the children, find the inorder succesor node then swap the root data with inorder
     // succesor data, call delete on inorder succesor node.
     // It will be done recursively till node will be found with single child or no child (base condition).
       tmpnode = InOrderSuccesor(root);
       root->data = tmpnode->data;
       root->right = DeleteNode(root->right, tmpnode->data); 
    }

    // traverse if right node is not found to delete
    if(root->data > data) {
       root->left = DeleteNode(root->left, data);
    } else {
       root->right = DeleteNode(root->right, data);
    }

    return root;
}

void PrintInOrder(bstree* root)
{
   if(root == NULL) {
     return;
   }
   PrintInOrder(root->left);
   cout<<root->data<<" ";
   PrintInOrder(root->right);
}

int main()
{
   bstree* root = CreateTreeNode(20);
   InsertData(root, 30);
   InsertData(root, 40);
   InsertData(root, 50);
   InsertData(root, 35);
   InsertData(root, 25);
   InsertData(root, 38);
   InsertData(root, 32);
   InsertData(root, 10);
   InsertData(root, 15);
   InsertData(root, 5);
   PrintInOrder(root);
   cout<<endl;
   // Perform Deletion
   root = DeleteNode(root, 20);
   PrintInOrder(root);
   cout<<endl;
   return 0;
}
