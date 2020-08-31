/* Given the root of a binary tree, find the most frequent subtree sum. The subtree sum of a node is the sum of all values under a node, including the node itself.

For example, given the following tree:

  5
 / \
2  -5

Return 2 as it occurs twice: once as the left leaf, and once as the sum of 2 + 5 - 5.
*/

/* Soln: Visit asusual left, right and root for each subtree and keep calculating the sums(left sum + right sum
 * + root node) and keep storing/updating sums in a unordered_map as sum(key) and count(value).
 * In last find out the sum which occured max number of time */

