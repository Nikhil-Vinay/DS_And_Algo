/*********************** BST ***************************/
/******* To understand bst deletion go through bst1.c **************/
/*** 1. If node if leaf node, simply delete the node.
 *   2. If node has only one child, copy the child to node and delete the child.
 *   3. If node has two children, find inorder succesor of the node. Copy the data os inorder succesor to the node.
 *      and delete the inorder succesor. It can be done similarly with inorder predeccor also.
 */
#include<stdio.h>
#include<stdlib.h>

#define GET_NODE(node, indata) \
  do {                 \
      node = calloc(1, sizeof(node_t)); \
      node->left = NULL; \
      node->right = NULL; \
      node->data = indata;  \
  } while(0)

#define FREE_AND_NULL(node) \
   do {                    \
        if(node) {         \
           free(node);      \
           node = NULL;    \
        }                  \
   } while(0)


typedef struct node_s
{
  struct node_s *left;
  struct node_s *right;
  int data;
}node_t;

/*** Inorder printing ********/
void print_tree(node_t *root) {
  if(root == NULL) {
     return;
  }
  print_tree(root->left);
  printf("%d\n", root->data);
  print_tree(root->right);
}

/****************** BST ****************************/
node_t* Insert(node_t *root, int data) {
  // create node
  node_t *new_node;
  if(root == NULL) {
     GET_NODE(new_node, data);
     root = new_node;
     return root;
  }
 
  if(root->data > data) {
    root->left = Insert(root->left, data);
  }
  else {
    root->right = Insert(root->right, data);
  }
  
  return root;
}

node_t *GetSuccesor(node_t *root) {
   if(root->right) {
      node_t *tmp = root->right;
      while(tmp->left) {
        tmp = tmp->left;
      }
      return tmp;
   }
   return NULL;
}

node_t* Delete(node_t *root, int data) {
  if(root == NULL) {
    return;
  }

  if(root->data > data) {
     root->left = Delete(root->left, data);
  }

  if(root->data < data) {
     root->right = Delete(root->right, data);
  }

  if(root->data == data) {
     // if root has only left child
     if(root->right == NULL) {
        node_t *tmp = root->left;
        FREE_AND_NULL(root);
        return tmp;
     }
     // if root has only right child
     if(root->left == NULL) {
        node_t *tmp = root->right;
        FREE_AND_NULL(root);
        return tmp;  
     }
     // above two condition will work if if root has both children null as leaf node
     // if root has left and right both child
     node_t *suc = GetSuccesor(root);
     root->data = suc->data;
     root->right =  Delete(root->right, suc->data);
  }

  return root;
}

int main()
{
  node_t *root = NULL;
  root = Insert(root, 50);
  root = Insert(root, 30);
  root = Insert(root, 20);
  root = Insert(root, 40);
  root = Insert(root, 70);
  root = Insert(root, 60);
  root = Insert(root, 80);
  printf("Printing tree \n");
  print_tree(root);
  int key = 50;
  printf("Deleting the element: %d\n", key);
  root = Delete(root, key);
  print_tree(root); 
  return 0;
}
