/* There is a string given which has space seperated positive and negative numbers. You need to build a balanced binary tree with numbers and find out how many subtree exists with sum K.
 *
Note: cin ignores white space (space, \n) but getline doesnot ignore so, we need to call cin.ignore();
      when we get multiple input in competitive programming, and we use getline thenwe need to use cin.ignore().
      while(t--){
         cin.ignore();
         getline(cin, str)
      }

Note: We are using map to build a complete binary tree by given array, we can use unordered_map to make time complexity of building tree is O(N) instead of O(nlogn). Second option is we can build the tree using level order traversal
with help of queue.

*/

#include<iostream>
#include<bits/stdc++.h>
#include<string.h>

using namespace std;

class Node
{
   public:
   int data;
   Node* left;
   Node* right;
   Node(int indata) {
     data = indata;
     left = right = NULL;
   }
};

vector<int> GetNodesArrayFromString(string s)
{
   vector<int> vct;
   char* str = (char*) s.c_str();
   char* token = strtok(str, " ");
   while(token != NULL){
      //vct.push_back(stoi(token));  // c++11
      vct.push_back(atoi(token));
      token = strtok(NULL, " ");
   }
   return vct;
}

Node* BuildTree(vector<int> nodeVct)
{
   Node* root = NULL;
   int n = nodeVct.size();
   map<int, Node*> nodeMap;
   for(int i = 0; i < n; i++) {
       if(i == 0) {  // root node
          root = new Node(nodeVct[i]);
          nodeMap.insert(make_pair(i, root));
       } else {
          Node* tmp = new Node(nodeVct[i]);
          nodeMap.insert(make_pair(i, tmp));
          int parent = (i-1)/2;
          if( i == (parent*2+1) ) {  // left child
            nodeMap[parent]->left = tmp;
          } else {  // right child
            nodeMap[parent]->right = tmp;
          }
       }
   }
   return root;
}

void PreOrder(Node* root)
{
   if(root == NULL) {
     return;
   }
   cout<<root->data<<endl;
   PreOrder(root->left);
   PreOrder(root->right);
}

int main()
{
   string str = "1 2 -3 4 -5 6 -10";
   vector<int> nodeVct = GetNodesArrayFromString(str);
   //for(int i = 0; i < nodeVct.size(); i++) {
   //  cout<<nodeVct[i]<<" ";
   //}
   cout<<endl;
   Node* root = BuildTree(nodeVct);

   cout<<"PreOrder is: "<<endl;
   PreOrder(root);
   return 0;
}

