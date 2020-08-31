/* print next greater element in forward direction for each element of an array */
/* Example: array: 1 4 2 6 1 8
 *          output 4 6 6 8 8 -1
 */
          
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<size_t N>
void print_next(int (&arr) [N])
{
   int *out = new int[N];
   stack<int> st;
   out[N-1] = -1;  // next large element for lat element will be -1
   st.push(arr[N-1]);
   for(int i = N-2; i >= 0; i--) {
      while(!st.empty() && (arr[i] > st.top())) {
         st.pop();
      }
      if(st.empty()) {
          out[i] = -1;  // no large element for element at this index
      } else {
          out[i] = st.top();
      }
      st.push(arr[i]);
   }

   // print output array
   for(int i = 0; i < N; i++) {
      cout<<out[i]<<" ";
   }
   cout<<endl;
   delete[] out;
}

int main()
{
   int arr[6] = { 1, 4, 2, 6, 1, 8};
   print_next(arr);
   return 0;
}
