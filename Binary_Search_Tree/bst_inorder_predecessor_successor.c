/********** Find inorder predecessor and succesor of a bst.
 * In case the given key is not found in bst, then return the two values, within which the key will lie */

/***
 * 1. If root is null, then return null.
 * 2. If key is found then,
 *    a. if left subtree is not null, the predecessor child will be rightmost child of left subtree or left
 *       child itself.
 *    b. if right subtree is not null, the succesor will be th eleftmost child of right subtree or right
 *       child itself.
 * 3. If key is smaller the root node, set succesor as root, search recursively in left subtree.
 * 4. If key is bigger than root node, set predecessor as root, search recursively in right subtree.
 */

/* Note: Iterative solution of this problem is present in this folder: bst_inorder_succesor.cpp */

#include<stdio.h>
#include<stdlib.h>

#define GET_NODE(node, indata) \
  do {                 \
      node = calloc(1, sizeof(node_t)); \
      node->left = NULL; \
      node->right = NULL; \
      node->data = indata;  \
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

node_t*  Insert(node_t *root, int data) {
  // create node
  node_t *new_node;
  if(root == NULL) {
     GET_NODE(new_node, data); 
     root = new_node;
     printf("inserting node with data = %d\n", root->data);
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

void FindPreSuc(node_t *root, node_t **pre, node_t **suc, int key) {
   // base case
   if(root == NULL) {
      return;
   }

   if(root->data == key) {
      // maximum value in left subtree is predecessor
      if(root->left) {
         node_t *tmp = root->left;
         while(tmp->right) {
           tmp = tmp->right;
         }
         *pre = tmp;
      }
     
      // minimum value in right subtree is succesor
      if(root->right) {
         node_t *tmp = root->right;
         while(tmp->left) {
           tmp = tmp->left;
         }
         *suc = tmp;
      }
      return;
   }

   // if key is smaller than root
   if(key < root->data) {
     *suc = root;
     FindPreSuc(root->left, pre, suc, key);     
   }

   // if key is larger than root
   if(key > root->data) {
      *pre = root;
      FindPreSuc(root->right, pre, suc, key);
   }
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

  int key = 70;
  node_t *pre = NULL, *suc = NULL;
  FindPreSuc(root, &pre, &suc, key);  // here address of pointer needs to be passed bcoz pointer is not
                                      // yet allocated, if pointer is allocated the no need to pass add of ptr
                                      // In c++, we can pass as reference
  if(pre) {
     printf("Predecessor is %d\n", pre->data);
  }

  if(suc) {
     printf("Successor is %d\n", suc->data);
  }

  return 0;
}
