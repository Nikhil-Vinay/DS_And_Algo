/*********** Print All binary numbers of n digits *************/

/* same as jumping number approach, we are knowing next digit addition is always 0 or 1.
 * We can apply this methid to solve any problem, if we are knowing the digit pattern in any number or
 * character pattern in any string 
 * Time complexity - O(n), n is number of numbers 
 * Note: Here we are printing as integers so, 001 will be printed as 1. If we need to print exact then
 * string should be used. string class object is perfect for that with concatenation*/

/* Variation of this problem: Print all binary numbers of n digits which doesn't have consecutive 1s.
 * This prob can be derived in any way. It is exactly similar to jumping number problem.
 * Solution of jumping number problem is in graph section */
  

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void PrintBinaryUtil(int num, int digitcount, int curdigitcount)
{
  if(curdigitcount > digitcount){
     cout<<num<<endl;
     return;    
  }
  PrintBinaryUtil(num*10+0, digitcount, curdigitcount+1);
  PrintBinaryUtil(num*10+1, digitcount, curdigitcount+1);
  return;
}

void PrintBinary(int n)
{
  PrintBinaryUtil(0, n, 1);
  return;
}

int main()
{
   int n;
   cout<<"Eneter the digit count for printing binary numbers: "<<endl;
   cin>>n;
   PrintBinary(n);
   return 0;
}

