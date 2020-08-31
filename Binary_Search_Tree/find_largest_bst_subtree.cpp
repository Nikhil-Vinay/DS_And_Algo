/* Given a tree, find the largest tree/subtree that is a BST.
 *
 * Given a tree, return the size of the largest tree/subtree that is a BST.
 */

/* SOlution: Any tree/subtree is BST if its left subtree and right subtree is bst and max of left subtree is lessthan the root and min of right subtree is greater than the root.
 *
 * If this rool fails for any side's left and right, no need to check for that subtree but we need to check all subtrees.
 */
