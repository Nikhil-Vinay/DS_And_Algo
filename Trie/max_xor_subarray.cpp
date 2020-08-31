/*** There is a given array, find out the maximum subarray xor in array ***/
/* brute force solution time complexity = O(n^2) */
/* left node of trie means 0 and right node means 1 */
/* Soultion: Array = 1, 3, 5, 8, 2
 * we inserted sub 1, (1^3), (1^3^5) in trie in 3 iteration.
 * In 4th iteration, element is 8
 * All subarrays ends at 8 are: (1,3,5,8), (3,5,8), (5,8) and 8
 * Next insertion element in trie = (1^3^5^8)
 * Get xor of all subarrays ends at 8 as following:
 * (1^3^5^8) ^ (1) = (3^5^8)
 * (1^3^5^8) ^ (1^3) = (5^8)
 * (1^3^5^8) ^ (1^3^5) = (8)
 *
 * traverse in trie and get the maximum subarray xor then insert (1^3^5^8).
 * 
 * Do the above steps for each index elements.
 */


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class trieNode
{
   public:
   trieNode* left;
   trieNode* right;
   trieNode(): left(NULL), right(NULL) {}
};

void insertNumber(trieNode* root, int n)
{
   trieNode* curNode = root;
   for(int i = 31; i >= 0; i--) {
      int b = (n>>i) & 1;
      if (b == 0) {
          if(curNode->left == NULL) {
             curNode->left = new trieNode();
          }
          curNode = curNode->left;
      } else {
          if(curNode->right == NULL) {
             curNode->right = new trieNode();
          }
          curNode = curNode->right;
      }
   }
}

int findMaxXor(trieNode* root, int val)
{
   int max_xor = 0;
   // find for each element (at index i) what could be the max xor possible with other elements
   trieNode* curNode = root;
   for(int j = 31; j >= 0; j--) {
      int b = (val>>j) & 1;
      int tmp = 0;
      if(curNode) {
         if(b == 0) {  // need to find 1 to maximize xor at this jth index
            if (curNode->right) {
               curNode = curNode->right;
               tmp = 1;
            } else {
               curNode = curNode->left;
               tmp = 0;
            }
         } else {      // need to find 0 to maximize xor at this jth index 
            if (curNode->left) {
               curNode = curNode->left;
               tmp = 0;
            } else {
               curNode = curNode->right;
               tmp = 1;
            }
         }
         max_xor |= (tmp << j);
      }
   }
   return max_xor;
}

int main()
{
   int arr[4] = { 1, 2, 3, 4 };
   trieNode* root = new trieNode();
   int max_xor = 0;
   int tmp_xor = 0;
   insertNumber(root, max_xor);
   for(int i = 0; i < 4; i++) {
      tmp_xor ^= arr[i];
    
      max_xor = max(max_xor, tmp_xor ^ findMaxXor(root, tmp_xor));
      max_xor = max(max_xor, tmp_xor); 
      insertNumber(root, tmp_xor);

   }
   cout<<"Max subarray xor: "<<max_xor<<endl;
   return 0;
}
