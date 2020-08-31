/********************* Asked in Goldman Sachs *****************************/

/****** Given two BST, we need to find one two numbers which sums upto a given a number. It's mandatory that
 * one number will be from one BST and other will be from second BST. ********/

/** Naive solution: For each element(n) of BST-1m we will search in BST-2 for (sum-n).
 *  Note: We can think as time complexity will be O(mlogn). m - number of node in BST-1 and n- number of nodes in
 *        BST-2.
 *        But, here both are simple BST not balanced BST so, worst case if BST is skewed the time complexity
 *        can be O(n) for each search in second BST, then whole time complexity will be O(mn)
 */

/** A very good is solution is: 
 * create two arrays of size m and size n.
 * store inorder of BST-1 in array-1 of size m. [inorder elements will be in ascending order sorted]        
 * store inorder of BST-2 in array-2 of size n. [inorder elements will be in ascending order sorted]
 *
 * Now, we have two sorted arrays, we can easily find the two numbers eual to sum as having two pointers.
 * one pointer at begining of array-1 and second pointer at end of array-2
 */

/** Method-2 is based on similar concept of method - 1. Only we can apply same priciple in recursive based
 * solution. Little tricky, but interesting. ******/

/***Nikhil code for both and enjoy ! :-) *****/
/*** Will do later, understood all, it's my solution :-) **********/        
