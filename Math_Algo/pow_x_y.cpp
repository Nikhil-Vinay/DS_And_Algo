/******** Calculate pow(x,y) in efficient way [not repetitive multiplication] ********************/

/* Note: Pow(x, y) [x*x*x......y times]   // O(n) 
 * The below solution calculates pow(x, y) in O(logn) time
 */

/* Used property in solution:
 * pow(x, y) = pow(x, y/2) * pow(x, y/2);      // if y is even
 * pow(x, y) = x * pow(x, y/2) * pow(x, y/2);  // if y is odd
 */
 

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int my_pow(int x, int y)
{
  if(y == 1) {
    return x;
  }
  int ret = 0;
  int temp = my_pow(x, y/2);
  
  if(y%2 == 0) {
    ret = temp*temp;
  } else {
    ret = x*temp*temp;
  }

  return ret;
}

int main()
{
   int x = 10;
   int y = 3;
   cout<<my_pow(x, y)<<endl; 
   return 0;
}
