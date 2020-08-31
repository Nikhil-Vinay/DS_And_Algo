/*   Merge two sorted linked list, Time complexity - O(n1+n2)  */

/** A problem based on merging the two sorted list is - Flatten the singly linked list
 *  5 -> 10 ->  80 ->  100 -> 120
 *  |     |     |       |
 *  6->7 12->13 81->82 110->116
 *  |     |     |
 *  8    14     85
 *
 *  Convert to a singly sorted linked list from above list.
 *
 *  Solution: Use merging of two sorted list and act recursively from last on the input list.(NlogN)
 *
 *  Note: If list are random(not sorted) and we need to flatten then we just need to join the list to flatten
 *  Apply same concept recursively from end but no need to sorted merge so time complexity - O(N).
 *  
 *  It can be solved iteratively also but recursively is better to understand */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef struct node_s {
  int data;
  struct node_s *next;
}node_t;

node_t* AddNodeAtBegining(node_t* node, int indata) {
  node_t *new_node = new node_t;
  new_node->data = indata;
  new_node->next = NULL;

  if(node == NULL){
    node = new_node;   
  } else {
    new_node->next = node;
  }
 
  return new_node;
}

void PrintList(node_t* node)
{
   if(node == NULL)
     return;
   while(node) {
     cout << node->data<<endl;
     node = node->next;
   };
   return;
}

node_t* MergeList(node_t *list1, node_t* list2)
{
   if(list1 == NULL)
      return list2;
   if(list2 == NULL)
      return list1;

   node_t* tmp = NULL;
   node_t* tmp2 = NULL;
   while(list1 && list2) {
      if(tmp == NULL) {
         if(list1->data <= list2->data) {
            tmp = list1;
            tmp2 = list1;
            list1 = list1->next;
         } else {
            tmp = list2;
            tmp2 = list2;
            list2 = list2->next;
         }
      } else {
         if(list1->data <= list2->data) {
            tmp->next = list1;
            tmp = tmp->next;
            list1 = list1->next;
          } else {
            tmp->next = list2;
            tmp = tmp->next;
            list2 = list2->next;
          }
      }
   }

   if(list1) {
      tmp->next = list1;
   }
   if(list2) {
      tmp->next = list2;
   }

   return tmp2; 
}

int main()
{
   node_t* list1 = NULL;
   node_t* list2 = NULL;

   list1 = AddNodeAtBegining(list1, 50);
   list1 = AddNodeAtBegining(list1, 40);
   list1 = AddNodeAtBegining(list1, 30);

   list2 = AddNodeAtBegining(list2, 55);
   list2 = AddNodeAtBegining(list2, 45);
   list2 = AddNodeAtBegining(list2, 35);
   list2 = AddNodeAtBegining(list2, 25);

   cout<<"Printing List-1"<<endl;
   PrintList(list1);
   cout<<"Printing List-2"<<endl;
   PrintList(list2);

   node_t *list3 = MergeList(list1, list2);
   cout<<"Printing Merged List: "<<endl;
   PrintList(list3);
 
   return 0;
}
