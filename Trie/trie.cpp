/**********  Trie data Structure (Insert, Delete, Query, Update) *****************/
/* Using Trie, search complexities can be brought to optimal limit (key length). If we store keys in binary 
 * search tree, a well balanced BST will need time proportional to M * log N, where M is maximum string length 
 * and N is number of keys in tree. Using Trie, we can search the key in O(M) time. However the penalty is on 
 * Trie storage requirements (Please refer Applications of Trie for more details)
 *
 * It is called dictionary implementatio also.
 * SUppose N strings are "abcd", "adbe", "pq",......
 * In balanced BST, time complexity to search a string is - logN x M(max string length).[For every node, we need
 *                  to traverse for M character to check for full string is present or not]
 * In trie, serch complecsity will be M [max length of string]
 *
 * Note: below implementation is as explained above.
 * If space really matters then we can use set instead of fixed array of length 26. In this case only used node
 * inserted in set so no wastage of memory but set is internally balanced binary tree so, total trie search time
 * complexity will increase to log(26) x M. It is also good because log(26) is constant so we can ignore this.
 */

/* Questions related to trie:
 * 1. Create effective dictionary.
 * 2. There are set of n number of strings, find longest common prefix of all strings.
 * 3. There is a set on n number of strings, given a string str. Return all strings of set which has str as 
 *     prefix.
 */
     
#include<bits/stdc++.h>
#include<iostream>

#define ALPHABET_COUNT 26
using namespace std;

#define DELETE_NODE(ptr) \
    do {                \
       if(ptr) {        \
          delete ptr;   \
          ptr = NULL;   \
       }               \
    } while(0)

class TrieNode{
   TrieNode* node[ALPHABET_COUNT];
   int strcount;
   public:
   TrieNode() {
     for(int i = 0; i < ALPHABET_COUNT; i++) {
        node[i] = NULL;
     }
     strcount = 0;
   }

   TrieNode* GetSubNode(int i) {
      return node[i];
   }

   void SetSubNode(int i, TrieNode* inNode) {
      node[i] = inNode;
   }

   void SetStrCount() {
      strcount++;
   }
   
   int GetStrCount() {
      return strcount;
   }

   void ResetStrCount() {
      strcount = 0;
   }
 
   ~TrieNode() {
      for(int i = 0; i < ALPHABET_COUNT; i++) {
         DELETE_NODE(node[i]);
      }
   }
};

TrieNode* InsertString(TrieNode* root, string str) {
   if(root == NULL) {
      return NULL;
   }

   TrieNode *tmpRoot = root;
   for(int i = 0; i < str.length(); i++) {
      if(tmpRoot->GetSubNode(str.at(i) - 'a') == NULL) {
         tmpRoot->SetSubNode((str.at(i) - 'a') , new TrieNode());
      }  
      tmpRoot = tmpRoot->GetSubNode(str.at(i) - 'a');
   }
   tmpRoot->SetStrCount();
   return root;
}

int SearchString(TrieNode* root, string str) {
  int found = 0;
  if(root == NULL) {
     return 0;
  }

  for(int i = 0; i < str.length(); i++) {
    if(!root->GetSubNode(str.at(i) - 'a')){
       break;
    }
    if(i == str.length()-1) {
      found = (root->GetSubNode(str.at(i) - 'a'))->GetStrCount();   
    }
    root = root->GetSubNode(str.at(i) - 'a');
  }
  return found;
}

TrieNode* DeleteString(TrieNode* root, string str) {
   // in this function, first we need to make string count is 0, if that string exists
   // next, if that node is dead node (note used in any other string, that should be deleted)
   // currently, we are taking care of only first part, later we will implement second one
   if(root == NULL) {
     return NULL;
   }
   TrieNode *tmpRoot = root;
   for(int i = 0; i < str.length(); i++) {
    if(!tmpRoot->GetSubNode(str.at(i) - 'a')){
       break;
    }  
    if(i == str.length()-1) {
      (tmpRoot->GetSubNode(str.at(i) - 'a'))->ResetStrCount();
    } 
    tmpRoot = tmpRoot->GetSubNode(str.at(i) - 'a');
  }
  return root;
}

TrieNode* UpdateString(TrieNode* root, string oldstr, string newstr) {
   // delete old string
   root =  DeleteString(root, oldstr);
   // insert new string
   root = InsertString(root, newstr);
   return root;
}

void DeleteTrie(TrieNode* root) {
   // It would be interesting n should be recursive
   //if(root == NULL) {
   //   return;
   //}
#if 0
   for (int i = 0; i < ALPHABET_COUNT; i++) {
      if(root->GetSubNode(i)) {
        DeleteTrie(root->GetSubNode(i));
        cout<<"deleteing node"<<endl;
        delete root;
        root = NULL;
      }
   }
   //delete root;
  #endif

   // No need to do all drama for recursive delete.
   // checkout the destructor of class TrieNode.
   DELETE_NODE(root); // It will delete al node
   return;
}

int main() {
  // root node
  TrieNode* root = new TrieNode();
  //root = InsertString(root, "nikhil");
  //root = InsertString(root, "vinay");
  //root = InsertString(root, "nikhil");
  //root = InsertString(root, "nik");
  //root = InsertString(root, "nik");
  root = InsertString(root, "nik");
  root = InsertString(root, "vin");
  cout << "Count of string nikhil is - "<< SearchString(root, "nikhil")<<endl; 
  cout << "Count of string vinay is - "<< SearchString(root, "vinay")<<endl; 
  cout << "Count of string nik is - "<< SearchString(root, "nik")<<endl;

  //root = DeleteString(root, "nikhil");
  cout << "Count of string nikhil is - "<< SearchString(root, "nikhil")<<endl;

  DeleteTrie(root);
  cout << "Count of string nikhil is - "<< SearchString(root, "nikhil")<<endl; 
  cout << "Count of string vinay is - "<< SearchString(root, "vinay")<<endl; 
  cout << "Count of string nik is - "<< SearchString(root, "nik")<<endl;  
  return 0;
}

/***************** SOME TRIE BASED PROBLEMS ************************************/

/* Microsoft:
 * Given a dictionary of words and string made up of those words (no spaces), return the original sentence in a
 * list. if there is more than on epossible reconstruction, return any of them. If there is no possible recons-
 * truction, then return null.
 *
 * Example: GIven the set of words - "quick", "brown", "the", "fox". and the string is - "thequickbrownfox", you
 * should return ["the", "quick", "brown", "fox"]
 *  Given the set of words "bed", "bath", "bedbath", "and", "beyond" and the string is - "bedbathandbeyond". you
 *  should return either ["bed","bath","and","beyond"] or ["bedbath","and","beyond"].
 *
 */ 
