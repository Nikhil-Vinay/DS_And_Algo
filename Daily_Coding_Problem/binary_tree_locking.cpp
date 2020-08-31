/*************** Binary Tree Locking (Google) ****************************************/

/* Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its 
 * descendants or ancestors are not locked.
 *
 * Design a binary tree node class with the following methods:
 *
 * is_locked, which returns whether the node is locked
 * lock, which attempts to lock the node. If it cannot be locked, then it should return false. Otherwise, it 
 * should lock it and return true.
 * unlock, which unlocks the node. If it cannot be unlocked, then it should return false. Otherwise, it should 
 * unlock it and return true.
 *
 * You may augment the node to add parent pointers or any other property you would like. You may assume the 
 * class is used in a single-threaded program, so there is no need for actual locks or mutexes. Each method 
 * should run in O(h), where h is the height of the tree.
 */

/* Note: The main beauty of this problem is each method should run in O(h) time.
 * We'll have a flag with each node, which will set/reset based on lock/unlock. So, time complexity for is_locked
 * and unlock method id O(1).
 * lock method: We need to check all descendants and ancestor. If any of descendant and ancestor is locked then
 * this method will return false. We need to have a parent pointer in each node so we could track all ancestors
 * for the given node. But for tracking descendants, we need to track all nodes in left and right subtree of the
 * given node so, here time complexity - O(h) will fail. h is height og the tree.
 *
 * So, the best solution is we will have a addition count integer flag in each node. Once a node is locked, we'll
 * increase the count flag of all ancestors by 1 and once a node is unlocked, we'll decrease the count flag of
 * all ancestors by 1. This way if the given node has count flag greater than zero means some of its descendant
 * is locked. So, we don't need to track all nodes of left and right subtree of the given node.
 *
 */

/* Note: I think if above concept is clear, it can be coded very easily. So, coding part is left blank here */
