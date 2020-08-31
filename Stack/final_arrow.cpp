/** There is an number of arrow sequence given:
 *  n means: n arrow is going left to right.
 * -n means: n arrow is going right to left.
 * We need to find out final arrow with direction.
 *
 * Example: 1, -2, -3, 4, -2 -1
 *          1  // 1 arrow going to right
 *         -2  // 2 arrow going to left which will collide with above 1 and finally 1 will go to left
 *         -3  // 3 arrow going to left without any obstacle
 *          4  // 4 arrow going to right
 *         -2  // 2 arrow going to left which will collide with above 4 and finally 2 arrow going to right
 *         -1  // 1 arrow going to left which will collide with above 2 and finally 1 arrow going to right
 *
 *         As per above analysis, 4 arrow went to left and 1 arrow went to right side.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<size_t N>
void FinalArrow(int (&arr)[N])
{
   // it is solved by stack
   stack<int> st;
   int left = 0;
   int right = 0;
   for(int i = 0; i < N; i++) {
      int numArrow = arr[i];
      if(st.empty()){  // if stack is empty, push the aroow count irrespective of left and right
         st.push(numArrow);
      } else if(numArrow > 0) {  // if arrow is going right side, keep pushing
         st.push(numArrow); 
      } else {
         while(!st.empty()) {
            if(st.top() > 0 && numArrow < 0){
               int tmp = st.top();
               st.pop();
               numArrow += tmp; 
            } else {
               break;
            }
         }
         if(numArrow != 0) {
           st.push(numArrow);
         }
      }
   }

   while(!st.empty()){
       int tmp = st.top();
       st.pop();
       if(tmp > 0) {
          right += tmp;
       } else {
          left += tmp;
       }
    }
    cout<<"Arrow going to leftwards: "<<left<<endl;
    cout<<"Arrow going to rightwards: "<<right<<endl;
}

int main()
{
   int arr[7] = {1, -2, 1, -3, 4, -2, -1};
   FinalArrow(arr);
   return 0;
}
