/**** There are n contigious numbers from 1...N in an array, one number is missing out of them, find out that */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/* Method - 1 :
 * Get sum by arithmetic progression method [1..N].
 * Find number by substracting A.P sum - total array sum.
 * Time complexity is O(N).
 * This method is proper if numbers are in perticular order, A.P, G.P, H.P or hybrid of any as A.P+G.P etc.
 */

#if 0
int FindNumber1(int *arr, int n)
{
  int totalsum = n*(n+1)/2;
  int arrsum = 0;
  for(int i = 0; i < n-1; i++) { 
     arrsum += arr[i];
  }
  return totalsum - arrsum;
}
#endif

/* Method - 2:
 * It just uses the XOR property as (a  ^ a) = 0
 */

#if 1
int FindNumber2(int *arr, int n)
{
   int arr_xor = 0;
   for(int i = 0; i < n-1; i++) {
       arr_xor  = arr_xor ^ arr[i];
   }

   int tot_xor = 0;
   for(int i = 1; i <= n; i++) {
       tot_xor = tot_xor ^ i;
   }

   return arr_xor ^ tot_xor;
}
#endif


int main()
{
  int n = 10;
  int arr[9] = { 1, 5, 6, 3, 2, 8, 9, 10, 7 };  // 4 is missing

  //cout<<"Missing number is: "<<FindNumber1(arr, sizeof(arr)/sizeof(arr[0])+1)<<endl;
  cout<<"Missing number is: "<<FindNumber2(arr, sizeof(arr)/sizeof(arr[0])+1)<<endl;

   return 0;
}
