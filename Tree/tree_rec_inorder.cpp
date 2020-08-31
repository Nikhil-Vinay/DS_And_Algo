/******************* Recursive Pre-Order Tree Traversal *********************/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/* In any kind of traversal, we'll handle by three states - 0, 1, 2 */

enum state
{
   ARRIVED_AT_ROOT,            // 0
   REARRIVED_BYLEFT_AT_ROOT,   // 1
   REARRIVED_BYRIGHT_AT_ROOT   // 2
};

typedef struct Node_s
{
  int data;
  struct Node_s* left;
  struct Node_s* right;
}Node;

void PreOrder(Node* root)
{
   if(root == NULL) {
      return;
   }
   typedef pair<Node*, int> node_pair;
   stack<node_pair> st;
   st.push(pair<Node*, int>(root, ARRIVED_AT_ROOT));

   while(!st.empty()) {
      node_pair np = st.top();
      st.pop();

      if(np.first == NULL || np.second ==  REARRIVED_BYRIGHT_AT_ROOT) {
         continue;
      }
 
      if(np.second == ARRIVED_AT_ROOT) {
         st.push(pair<Node*, int>(np.first, REARRIVED_BYLEFT_AT_ROOT));  // need to push it for right visit 
         st.push(pair<Node*, int>(np.first->left, ARRIVED_AT_ROOT));     // push next node to visit
      } else if(np.second == REARRIVED_BYLEFT_AT_ROOT) {
         cout<<np.first->data<<endl;
         st.push(pair<Node*, int>(np.first, REARRIVED_BYRIGHT_AT_ROOT)); // need to push it for returning, after
                                                                          // left, right visit
         st.push(pair<Node*, int>(np.first->right, ARRIVED_AT_ROOT));    // push for next node to visit
      }
   }
}

int main()
{
   Node *root = new Node();
   root->data = 1;
   root->left = new Node();
   root->left->data = 2;
   root->right = new Node();
   root->right->data = 3;

   root->left->left = new Node();
   root->left->left->data = 4;
   root->left->left->left = NULL;
   root->left->left->right = NULL;

   root->left->right = new Node();
   root->left->right->data = 5;
   root->left->right->left = NULL;
   root->left->right->right = NULL;

   root->right->left = new Node();
   root->right->left->data = 6;
   root->right->left->left = NULL;
   root->right->left->right = NULL;

   root->right->right = new Node();
   root->right->right->data = 7;
   root->right->right->left = NULL;
   root->right->right->right = NULL;

   PreOrder(root);
   
   return 0;
}
