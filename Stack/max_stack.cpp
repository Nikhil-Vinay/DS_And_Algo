/********************* Max Stack Problem ******************************/
/** Create a stack which could give max element in stack in O(1) time at any point *******/

/* Method-1: 
 *
 * Time Complexity - O(1), Space Complexity - O(N)
 * We will use an additional auxiliary stack which will hold exactly same number of elements what main stack has.
 * Auxiliary stack will have max element corresponds to each element in stack. After each push in main stack, we
 * compare the current pushed element with top of auxiliary stack and get a new max element which is pushed in
 * auxiliary stack.
 *
 * Method-2:
 *
 * Time Complexity - O(1), Space complexity - O(N)
 * This method is almost similar to method-1. Only difference is, we reduce space complexity in some cases. But,
 * in worst case here also space complexity will be O(N).
 * Unlike method-1, it won't have duplicate elements in auxiliary stack. New max element is pushed in auxiliary
 * stack only if new max element comes in main stack. After each pop from main stack we check if top of main stack is smaller than top of auxiliary stack then only pop happens from auxiliry stack also.
 *
 * Mehod-3:
 *
 * Time Complexity - O(1), Space complexity - O(1).
 *
 * This is the best method to implement the max stack with space complexity - O(1).
 * Here, we won't have any additional auxiliary stack, instead we'll have onle one integer which will hold the
 * max element always. Here trick is we have to make a relation between inserted element and max element.
 *
 * Suppose inserted element is x and (x > current_max_ement) then (2x - current_max_element) will be always
 * greater than x.
 * ===================|=================== (2X)
 * ------------(current_max_element < x)
 *
 * Above picture shows, ((2x-current_max_element) > x)  if (current_max_element < x)
 *
 * So, if inserting element(x) is greater than current max element, we will insert (2x-current_max_element) into
 * stack and current_max_element will be changed to x.
 *
 * While popping the element if we'll see the popped element is greater than the current_max_element, it means
 * current_max_element is the element which should be value of pop() operation and new current_max_element will
 * be changed by the above formula: 
 * new_current_max_element = (2 * current_max_element) - x [This is derived by insertion formula only]
 *
 * The below code is based on this method only.
 */
  
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void Insert(int n, stack<int> &s, int &max_elem)
{
   if(s.empty()) {
     max_elem = n;
     s.push(n);
   } else {
     if(n <= max_elem) {
        s.push(n);
     } else {
       s.push(2*n - max_elem);
       max_elem = n;
     }
   }
}

int Pop(stack<int> &s, int &max_elem)
{
  if(s.empty()) {
    cout<<"stack is empty, returning dummy value"<<endl;
    return -1;
  } else {
    if(s.top() < max_elem) {
       int x = s.top();
       s.pop();
       return x;
    } else {
       int x = max_elem;
       int new_max = (2*max_elem - s.top());
       max_elem = new_max;
       s.pop();
       return x;
    }
  }
}

int main() {
   stack<int> s;
   int max_elem = 0;

   // insert 1
   cout<<"Inserting - 1"<<endl;
   Insert(1, s, max_elem);   
   cout<<"Inserting - 5"<<endl;
   Insert(5, s, max_elem);   
   cout<<"Inserting - 3"<<endl;
   Insert(3, s, max_elem);   
   cout<<"Inserting - 6"<<endl;
   Insert(6, s, max_elem);

   cout<<"Popping elements: "<<endl;
   while(s.empty() == false) {
      cout<<Pop(s, max_elem)<<endl;
   }

   return 0;   
}
