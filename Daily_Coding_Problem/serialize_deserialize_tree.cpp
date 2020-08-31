/******* Prob-3 (Medium): Serialize/Deserialize a tree ***************/

/*  Given the root to a binaty tree, implement serialize(root), which serializes the tree into a string, and 
 *  deserialize(string) which deserialize the string back into the tree.
 */

/* Note: Serializing a tree means, storing the tree structure information into a file so, that we can reform 
 * the tree by information stored in file.
 * Storing the information into a file is called serialization of tree.
 * Recreation of tree from the information stored in file is called deserialization of tree */  

/* Note:
 * If given Tree is Binary Search Tree?
 * ====================================
 * If the given Binary Tree is Binary Search Tree, we can store it by either storing preorder or postorder 
 * traversal.
 *
 * If given Binary Tree is Complete Tree?
 * ======================================
 * A Binary Tree is complete if all levels are completely filled except possibly the last level and all nodes of
 * last level are as left as possible (Binary Heaps are complete Binary Tree). For a complete Binary Tree, level
 * order traversal is sufficient to store the tree. We know that the first node is root, next two nodes are node
 * s of next level, next four nodes are nodes of 2nd level and so on...
 *
 * If given Binary Tree is Full Tree?
 * ==================================
 * A full Binary is a Binary Tree where every node has either 0 or 2 children. It is easy to serialize such trees
 * as every internal node has 2 children. We can simply store preorder traversal and store a bit with every node
 * to indicate whether the node is an internal node or a leaf node.
 *
 * How to store a general Binary Tree?
 * ===================================
 * A simple solution is to store both Inorder and Preorder traversals.This solution requires requires space twice
 * the size of Binary Tree.
 * We can save space by storing Preorder traversal and a marker for NULL pointers.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{
}
