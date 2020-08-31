/* Implement merge sort of singly linked list */

/* Merge sort is most efficient sorting method in linked-list */
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node
{
   public:
   int data;
   node* next;
   node(int indata, node* innode): data(indata), next(innode) { }
};

node* insert_node_at_front(node* &list, int data)
{
   if(list == NULL) {
      list = new node(data, NULL);
      return list;    
   }

   node* tmpnode = new node(data, NULL);
   tmpnode->next = list;
   list = tmpnode;
   return list;
}

void print_list(node* list)
{
   node* first = list;
   while(first != NULL) {
     cout<<first->data<<" ";
     first = first->next;
   }
   cout<<endl;
}

/**************** merge sort ***********************/

node* merge(node* &list1, node* &list2)
{
   if(list1 == NULL && list2 == NULL) {
     return NULL;
   }
   if(list1 == NULL && list2) {
     return list2;
   }
   if(list2 == NULL && list1) {
     return list1;
   }

   node* tmplist = NULL;
   node* finallist = NULL;
   while(list1 != NULL && list2 != NULL) {
      if(list1->data <= list2->data) {
         if(tmplist == NULL) {
            tmplist = list1;
            finallist = tmplist;
            list1 = list1->next;
         } else {
            tmplist->next = list1;
            list1 = list1->next;
            tmplist = tmplist->next;
         }
      } else {
         if(tmplist == NULL) {
            tmplist = list2;
            finallist = tmplist;
            list2 = list2->next;
         } else {
            tmplist->next = list2;
            list2 = list2->next;
            tmplist = tmplist->next;
         }
      }
   }

   // add pending node
   if(list1) {
      tmplist->next = list1;
   } else if(list2) {
      tmplist->next = list2;
   } else {
     tmplist->next = NULL;
   }

   return finallist;
}
 
node* merge_sort(node* &list)
{
   // base condition
   if(list == NULL || list->next == NULL) {
      return list;
   }

   // find middle pointer
   node* slowptr = list;
   node* fastptr = list->next;

   while (fastptr && fastptr->next) {
      slowptr = slowptr->next;
      fastptr = fastptr->next->next;
   }

   // slowptr is at middle node
   node* second = slowptr->next;
   slowptr->next = NULL;
   merge_sort(list);
   merge_sort(second);

   list = merge(list, second);
   return list;
}

int main()
{
   node* list = NULL;
   list = insert_node_at_front(list, 10);  
   list = insert_node_at_front(list, 5);  
   list = insert_node_at_front(list, 2);  
   list = insert_node_at_front(list, 9);  
   list = insert_node_at_front(list, 20);  
   list = insert_node_at_front(list, 1);
   // 1 20 9 2 5 10  

   print_list(list);

   list = merge_sort(list);

   print_list(list);

   return 0;
}
