/**** Write a program to add the digits in two input given singly linked list
 *                 7->5->3->5->null
 *                    5->2->6->null
 * Riesult List->   8->0->6->1->null
 *
 * Note: 1. Reversing of list is not allowed
 *       2. Using stack is not allowed
 */

/* Note: In the below solution ,we are using map which has logn time complexity for searching.
 * We can use unordered_map to reduce the time complexity.
 *
 * It is very good approach to use map in case of singly linked list when we need previous node at any point
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node
{
   public:
   int data;
   node* next;
   node(int indata):data(indata), next(NULL) {}
   node(int indata, node* innext):data(indata), next(innext) {}
};

node* AddNodeAtStart(node* list, int data)
{
   if(list == NULL) {
     list = new node(data);
   }else {
     node* tmp = new node(data);
     tmp->next = list;
     list = tmp;
   }   
   return list;
}

void PrintList(node* list)
{
   while(list != NULL) {
     cout<<list->data<<" -> ";
     list = list->next;
   }
   cout<<"null"<<endl;
}

class listwrap
{
  public:
  node* list;
  map<node*, node*> pre;  // map to store, key as current node and val as previous node
  
  listwrap(node* list) {
     node* first = list;
     list = list->next;
     while(list != NULL) {
       pre.insert(pair<node*, node*>(list, first));
       first = list;
       list = list->next;
     }
     pre.insert(pair<node*, node*>(NULL, first));    
  }

  node* getTail() {
     map<node*, node*>::iterator it = pre.find(NULL);
     return (it != pre.end()) ? it->second : NULL;
  }

  node* getPre(node* inNode) {
     map<node*, node*>::iterator it = pre.find(inNode);
     return (it != pre.end()) ? it->second : NULL;    
  }
};

void AddList(node* &list1, node* &list2, node* &res)
{

   listwrap listwrap1(list1);
   listwrap listwrap2(list2);

   node* tmp1 = listwrap1.getTail();
   node* tmp2 = listwrap2.getTail();

   int sum = 0, carry = 0;

   while(tmp1 || tmp2) {
     if(tmp1 && tmp2) {
        sum = tmp1->data  + tmp2->data + carry;
     } else if (tmp1) {
        sum = tmp1->data + carry;
     } else if (tmp2) {
        sum = tmp2->data + carry;
     }

     if(res == NULL) {
        res = new node(sum%10);
     } else {
        node* newnode = new node(sum%10);
        newnode->next = res;
        res = newnode;
     }
     if(tmp1) {
        tmp1 = listwrap1.getPre(tmp1);
     }
     if(tmp2) {
        tmp2 = listwrap2.getPre(tmp2);
     }
     carry = sum/10;
   }

   // check is still carry is remaining
   if(carry > 0) {
     if(res == NULL) {
        res = new node(carry);
     } else {
        node* newnode = new node(carry);
        newnode->next = res;
        res = newnode;
     } 
   }
}

int main()
{
   // create two lists
   node* list1 = NULL;
   node* list2 = NULL;
   // 7->5->3->5
   list1 = new node(5);
   list1 = AddNodeAtStart(list1, 3); 
   list1 = AddNodeAtStart(list1, 5); 
   list1 = AddNodeAtStart(list1, 7);
   cout<<"First List is: "<<endl;
   PrintList(list1); 

   // 5->2->6
   list2 = new node(6);
   list2 = AddNodeAtStart(list2, 2);
   list2 = AddNodeAtStart(list2, 5);
   cout<<"Second List is: "<<endl;
   PrintList(list2); 

   node* reslist = NULL;
   AddList(list1, list2, reslist); 
   cout<<"Final List is: "<<endl;
   PrintList(reslist); 
}

