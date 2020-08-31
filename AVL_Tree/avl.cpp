/************ Create a self balanced binary search tree insert and delete function ************/
/************************ self balanced binary search tree is AVL tree ************************/

/* After inserting or deleting any node in avl tree, we keep on checking the balance factor of each node.
 * every node has an additional data has height. leaf node has height 1.
 * balance factor of a node = height of left node - height of right node.
 * balanced factor belongs [-1, 1] for a balanced node in AVL tree */

/* this code is just a modification of bst.cpp in this folder but here we are doing insertion by recursion 
 * though insertion hs been done iterativelt in bst.cpp.
 * Benefit of recursive call is - after inserting an element ar right place it comes back till root and we can
 * check/update balance factor for each node till root after inserting the element.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class bstree
{
   public:
   int data;
   bstree* left;
   bstree* right;
   int height; 
};

void PrintInOrder(bstree* root);

bstree* CreateTreeNode(int data)
{
  bstree* bst = new bstree();
  bst->data = data;
  bst->left = NULL;
  bst->right = NULL;
  bst->height = 1;
}

int Height(bstree* root)
{
   return root?root->height:0;
}

int BalanceFactor(bstree* root)
{
   // left child height - right child height
   return Height(root->left) - Height(root->right);
}

bstree* RightRotate(bstree* root)
{
   bstree* tmp = root->left;
   root->left = tmp->right;
   tmp->right = root;

   // adjust height of left and right subtree of tmp then finally height of tmp;
   if(tmp->left) {
      tmp->left->height = max(Height(tmp->left->left), Height(tmp->left->right)) + 1;
   }
   if(tmp->right) {
      tmp->right->height = max(Height(tmp->right->left), Height(tmp->right->right)) + 1;
   }
   tmp->height = max(Height(tmp->left), Height(tmp->right)) + 1;

   return tmp;
}

bstree* LeftRotate(bstree* root)
{
   bstree* tmp = root->right;
   root->right = tmp->left;
   tmp->left = root;

   // adjust height of left and right subtree of tmp then finally height of tmp;
   if(tmp->left) {
      tmp->left->height = max(Height(tmp->left->left), Height(tmp->left->right))  +1;
   }
   if(tmp->right) {
      tmp->right->height = max(Height(tmp->right->left), Height(tmp->right->right)) + 1;
   }
   tmp->height = max(Height(tmp->left), Height(tmp->right)) + 1;

   return tmp;
}

bstree* InsertData(bstree* root, int data)
{
   if(root->data > data) {
      // insertion in left
      if(root->left) {
        root->left = InsertData(root->left, data);
      } else {
        root->left = CreateTreeNode(data);
      }
   }

   if(root->data < data) {
      // insertion in right
      if(root->right) {
        root->right = InsertData(root->right, data);
      } else {
        root->right = CreateTreeNode(data);
      }
   }

   // update root->height
   root->height = max(Height(root->left), Height(root->right)) + 1;
   // balance the node if it is not balanced
   int bfactor = BalanceFactor(root);
   // if bfactor > 1 then left side unbalanced
   // if bfactor > -1 then right side unbalanced
   if(bfactor > 1 && root->left && data < root->left->data) { // Left-Left
      root = RightRotate(root);
   } else if (bfactor > 1 && root->left && data > root->left->data) { // Left-Right
      root->left = LeftRotate(root->left);
      root =  RightRotate(root);
   } else if (bfactor < -1 && root->right && data > root->right->data) { // Right- Right
      root = LeftRotate(root);
   } else if (bfactor < -1 && root->right && data < root->right->data) {  // Right-Left
      root->right = RightRotate(root->right);
      root = LeftRotate(root);
   }
 
   return root;
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
    bstree* retroot = root;

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
          return  NULL;
       }
       // if root has only one child
       else if(root->left && root->right == NULL) { 
          tmpnode = root->left;
          delete root;
          return tmpnode;
       }else if(root->right && root->left == NULL) { 
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
       else if (root->left && root->right) {
          tmpnode = InOrderSuccesor(root);
          root->data = tmpnode->data;
          root->right = DeleteNode(root->right, tmpnode->data);
       } 
    }

    // traverse if right node is not found to delete
    if(root->data > data) {
       root->left = DeleteNode(root->left, data);
    } else {
       root->right = DeleteNode(root->right, data);
    }

    // adjust the height
    root->height = max(Height(root->left), Height(root->right)) + 1;

    // balance the node if it is not balanced
    int bfactor = BalanceFactor(root);
    // if bfactor > 1 then left side unbalanced
    // if bfactor > -1 then right side unbalanced
    // We are checking the rotation type in different way here compared to done in data insertion
    // This method will work while data insertion also.
    if(bfactor > 1 && BalanceFactor(root->left) > 0) { // Left-Left        
       root = RightRotate(root);
    } else if (bfactor > 1 && BalanceFactor(root->left) < 0) { // Left-Right
       root->left = LeftRotate(root->left);
       root =  RightRotate(root);
    } else if (bfactor < -1 && BalanceFactor(root->right) < 0) { // Right- Right
       root = LeftRotate(root);
    } else if (bfactor < -1 && BalanceFactor(root->right) > 0) {  // Right-Left
       root->right = RightRotate(root->right);
       root = LeftRotate(root);
    }

    return root;
}

void PrintInOrder(bstree* root)
{
   if(root == NULL) {
     return;
   }
   PrintInOrder(root->left);
   cout<<root->data<< " ";
   PrintInOrder(root->right);
}

int main()
{
   cout<<"inserting 20"<<endl;
   bstree* root = CreateTreeNode(20);
   cout<<"inserting 30"<<endl;
   root = InsertData(root, 30);
   cout<<"inserting 40"<<endl;
   root = InsertData(root, 40);
   cout<<"inserting 50"<<endl;
   root = InsertData(root, 50);
   cout<<"inserting 35"<<endl;
   root = InsertData(root, 35);
   cout<<"inserting 38"<<endl;
   root = InsertData(root, 25);
   cout<<"inserting 38"<<endl;
   root = InsertData(root, 38);
   cout<<"inserting 32"<<endl;
   root = InsertData(root, 32);
   cout<<"inserting 10"<<endl;
   root = InsertData(root, 10);
   cout<<"inserting 15"<<endl;
   root = InsertData(root, 15);
   cout<<"inserting 5"<<endl;
   root = InsertData(root, 5);
   PrintInOrder(root);
   cout<<endl;
   // Perform Deletion
   cout<<"Deleting 20"<<endl;
   root = DeleteNode(root, 20);
   PrintInOrder(root);
   cout<<endl;
   return 0;
}
