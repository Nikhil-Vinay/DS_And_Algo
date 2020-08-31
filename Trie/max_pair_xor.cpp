/*** There is a given array, find out the maximum xor of any pair of two elements in array ***/
/* brute force solution time complexity = O(n^2) */
/* left node of trie means 0 and right node means 1 */
/* first insert all numbers of array in tree then check for each element of array with maximizing the xor
 * for what max xor corresponding to that elemt exists in trie */


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

int findMaxXorPair(trieNode* root, int* arr, int n)
{
   int max_xor = 0;
   for(int i = 0; i < n; i++) {
      // find for each element (at index i) what could be the max xor possible with other elements
      int num = arr[i];
      int cur_xor = 0;
      trieNode* curNode = root;
      for(int j = 31; j >= 0; j--) {
         int b = (num>>j) & 1;
         int tmp = 0;
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
         cur_xor |= (tmp << j);
      }
      max_xor = max (max_xor, cur_xor); 
   }
   return max_xor;
}

int main()
{
   int arr[6] = { 8, 1, 2, 15, 10, 5 };
   trieNode* root = new trieNode();
   for(int i = 0; i < 6; i++) {
      insertNumber(root, arr[i]);
   }
   int max_xor =  findMaxXorPair(root, arr, 6);
   cout<<"Max xor pair: "<<max_xor<<endl;
   return 0;
}
