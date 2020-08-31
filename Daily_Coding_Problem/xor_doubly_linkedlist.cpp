/********* Memory Efficient Doubly Linked List (XOR linked list) *************************/
/* This doubly linked list is called memoey efficient ebecause, it doesn't have two pointers (prev and next).
 * Instead, it has only pointer which holds xor of two pointers prev and next/
 *
 * every node will have a pointer npx(next previous xor).
 *
 * In this code, we will discuss about insertion and traversing in xor linked list.
 *
 * Insertion: insertion is done at begining.
 *
 * start ->null
 * i is inserted : 1 (start points to 1)
 * 2 is inserted: 2 -> 1 (start points to 2)
 * 3 is inserted: 3 -> 2 -> 1 (start points to 3)
 * 4 is inserted: 4 -> 3 -> 2 -> 1 (start points to 4)
 *
 */

#include<iostream>
#include<bits/stdc++.h>
#include<stdint.h>

using namespace std;

class Node
{
  public:
  int data;
  Node* npx;
  Node(int indata): data(indata), npx(NULL) { }
};

Node* XOR_Node(Node* add1, Node* add2)
{
  return (Node*) ((uintptr_t)(add1) ^ (uintptr_t)(add2)); 
}

void Insertnode(Node** start, int data)
{
  // create node
  Node* newnode = new Node(data);
  newnode->npx = XOR_Node(*start, NULL);

  if(*start != NULL) { // list is not null, update npx of start node
      Node* next = XOR_Node((*start)->npx, NULL); // get next of start node
      (*start)->npx = XOR_Node(next, newnode);
  }
 
  // shift start to new node
  *start = newnode;
}

void PrintList(Node* start)
{
  Node* cur = start;
  Node* prev = NULL;
  Node* next = NULL;

  while(cur != NULL) {
    cout<< cur->data<<" ";
    next = XOR_Node(cur->npx, prev);
    prev = cur;
    cur = next;
  }

  cout<<endl;
}

int main()
{
  Node* start = NULL;  
  Insertnode(&start, 1);
  Insertnode(&start, 2);
  Insertnode(&start, 3);
  Insertnode(&start, 4);

  cout<<"List is following: "<<endl;
  PrintList(start);
  return 0;
}
