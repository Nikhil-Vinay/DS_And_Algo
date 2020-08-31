/* 
 * Given an unsigned 8-bit integer, swap its even and odd bits. The 1st and 2nd bit should be swapped, the 3rd and 4th bit should be swapped, and so on.
 *
 * For example, 10101010 should be 01010101. 11100010 should be 11010001.
 *
 * Bonus: Can you do this in one line?
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int x = 10;
  // we are taking care till 8 bits only
  // 01010101 - 85
  // 10101010 - 175
  x = ((x & 85)<<1) | ((x & 175)>>1); 
  cout<<x<<endl;
  return 0;
}
