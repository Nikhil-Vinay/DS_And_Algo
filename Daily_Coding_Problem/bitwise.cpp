/* Given three 32-bit integers x, y, and b, return x if b is 1 and y if b is 0, using only mathematical or bit operations. You can assume b can only be 1 or 0.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int x = 8, y = 9;
  int b = 0;
  if(x & 1) {  // if x is odd
     if (!((x^b)^(x^1))) {
         cout<<x<<endl;
     } else {
         cout<<y<<endl;
     }
  } else {     // if x is even, or x with 1 to make it odd and apply the same if part odd method
    if (!(((x|1)^b)^((x|1)^1))) {
         cout<<x<<endl;
     } else {
         cout<<y<<endl;
     }     
  }

  return 0;
}
