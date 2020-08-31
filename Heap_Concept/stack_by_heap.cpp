/* Build a stack by using a heap only*/

/* Note: Idea here is, we have to add a rank with the incoming data in stack. rank will be incremented at each
 * insert and decremented at each pop. max heap will store the data as per rank of data. By this way, last coming
 * data will stay on top of the heap.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int g_rank = 0;
class mydata
{
  public:
  int rank;
  int val;
  mydata(int inrank, int inval):rank(inrank), val(inval) { }
};

class mycmp
{
   public:
   bool operator() (const mydata &obj1, const mydata &obj2) {
      return obj1.rank < obj2.rank;
   }
};
typedef priority_queue<mydata, vector<mydata>, mycmp > mystack_t; 

void push(mystack_t &stack, int val)
{
   mydata obj(++g_rank, val);
   stack.push(obj);
}

int pop(mystack_t &stack)
{
  if(!stack.empty()) {
     mydata obj = stack.top();
     stack.pop();
     --g_rank;
     return obj.val;
  }
  return -1;
}

bool isEmpty(mystack_t &stack)
{
   return stack.empty();
}

int main()
{
   mystack_t mystack;
   push(mystack, 10);
   push(mystack, 5);
   push(mystack, 25);
   push(mystack, 3);
   cout<<pop(mystack)<<endl;
   cout<<pop(mystack)<<endl;
   cout<<pop(mystack)<<endl;
   cout<<pop(mystack)<<endl;
   
   return 0;
}
