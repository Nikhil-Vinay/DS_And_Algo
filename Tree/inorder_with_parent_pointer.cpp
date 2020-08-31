/* If a tree is given where each node has a additional pinter to parent node as below:
   struct Node
   {
      int val;
      Node* left;
      Node* right;
      Node* parent;
   };

   You have to print all nodes by traversing any order you want but not recursively and dont use any stack.

   Soln: We have to take advantage of parent pointer of each node and inorder traversal is best suit in this case.
   Below code is not complete and have the logic only to traversal.
   Source: https://www.geeksforgeeks.org/inorder-non-threaded-binary-tree-traversal-without-recursion-or-stack/

   This question has been asked by FireEye.

*/

void inorder(Node *root) 
{ 
    bool leftdone = false; 
  
    // Start traversal from root 
    while (root) 
    { 
        // If left child is not traversed, find the 
        // leftmost child 
        if (!leftdone) 
        { 
            while (root->left) 
                root = root->left; 
        } 
  
        // Print root's data 
        printf("%d ", root->key); 
  
        // Mark left as done 
        leftdone = true; 
  
        // If right child exists 
        if (root->right) 
        { 
            leftdone = false; 
            root = root->right; 
        } else if (root->parent) { // If right child doesn't exist, move to parent 
            // If this node is right child of its parent, 
            // visit parent's parent first 
            while (root->parent && root == root->parent->right) { 
                root = root->parent; 
            }
            if (!root->parent)  // reached to root node 
                break; 
            root = root->parent; 
        } else {  // root node 
          break;
        } 
    } 
} 
