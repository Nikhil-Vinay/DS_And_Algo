/** Bitonic Array
 * A Bitonic array is an array which is strictly increasing or strictly decreasing or strictly increasing and then
 * striclty decreasing. There is only one peak in bitonic array either at end of array or in the middle of array.
 *
 * This problem solution is called bidirectional DP.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<size_t N>
int maxBitonicArray(int (&arr)[N])
{
   vector<int> left;
   vector<int> right;
   left.reserve(N);
   right.reserve(N);

   left[0] = 1;
   for(int i = 1; i < N; i++){
      int x = 1;
      for(int j = 0; j < i; j++) {
         if(arr[j] < arr[i]){
             x = max(x, left[j]+1);
         }
      }
      left[i] = x;
   }

   right[N-1] = 1;
   for(int i = N-2; i >= 0; i--){
      int x = 1;
      for(int j = i+1; j < N; j++) {
         if(arr[j] < arr[i]){
            x = max(x, right[j]+1);
         }
      }
      right[i] = x;
   }

   int max_len = 0;
   for(int i = 0; i < N; i++){
       max_len = max(max_len, left[i]+right[i]-1);
   }
   return max_len;
         
}         
   
int main()
{
   int arr[9] = {1,3,5,7,4,3,5,2,6};
   cout<<maxBitonicArray(arr)<<endl; 
   return 0;
}
