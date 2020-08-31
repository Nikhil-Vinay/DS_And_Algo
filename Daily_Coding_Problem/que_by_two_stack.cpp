/************* Implement a que by using two stacks *********************************/

/*** NOte: A que has FIFO property and a stack as LIFO or FILO property ********/

/** We can implement in two ways:
 * 1. We can have push in operation O(1) and pop in operation O(N).
 *    push an element simply but while popping store all elements from main stack to auxiliary stack the after
 *    popping the bottom element, transfer all elements from auxiliary stack to main stack.
 * 2. We can have pop in operation O(1) and push in operation O(N).
 *    while pushing an element first take all element from main stack to auxiliary stack then push the elemenet 
 *    and later transfer all elements from auxiliary stack to main stack. Pop simply from main stack.
 */
#include<iostream>
#include<bits/stdc++.h>

#define EMPTY  INT_MIN
using namespace std;

void Enque(stack<int> &main_stack, int data)
{
  main_stack.push(data);
}

int Deque(stack<int> &main_stack)
{
  stack<int> aux_stack;
  if(main_stack.empty())
  {
    return EMPTY;
  }

  int data;
  int ret;
  while(!main_stack.empty()){
     data = main_stack.top();
     main_stack.pop();
     if(!main_stack.empty()) {  
       aux_stack.push(data);
     }     
  }
  ret = data;
  while(!aux_stack.empty()){
    data = aux_stack.top();
    aux_stack.pop();
    main_stack.push(data);
  }

  return ret;   
}

int main()
{
   stack<int> main_stack;
   Enque(main_stack, 1);  
   Enque(main_stack, 2);  
   Enque(main_stack, 3);  
   Enque(main_stack, 4);

   cout<<Deque(main_stack)<<endl;  
   cout<<Deque(main_stack)<<endl;  
   cout<<Deque(main_stack)<<endl;  
   cout<<Deque(main_stack)<<endl;  
   return 0;
}
