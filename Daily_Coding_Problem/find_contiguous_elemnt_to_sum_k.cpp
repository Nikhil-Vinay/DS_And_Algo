/* Given a list of integers and a number K, print start and end index of contiguous elements of the list sum to K
 *
 * For example, if the list is [1, 2, 3, 4, 5] and K is 9, then it should print - index 1 and index 3 because   
 * [2, 3, 4], since 2 + 3 + 4 = 9.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template <size_t N>
void PrintTwoIndexesWhichSumsUptoK(int (&arr)[N], int k)
{
   int st_index = 0;
   int end_index = 0;
   int sum = arr[st_index];
   if(sum == k) {
     cout<< "Sum Found, start index = "<<st_index<<" end index = "<<end_index<<endl;
     return;
   }

   for(end_index = 1; end_index < N; end_index++) {
      sum += arr[end_index];

      // check if sum is achieved
      if(sum == k) {
        cout<< "Sum Found, start index = "<<st_index<<" end index = "<<end_index<<endl;
        return;
      }

      // if sum exceeded, remove elements from left side, till sum < k
      while(sum > k && st_index <= end_index) {
           sum -= arr[st_index];
           st_index++;    
      }

      // check if sum is achieved
      if(sum == k) {
        cout<< "Sum Found, start index = "<<st_index<<" end index = "<<end_index<<endl;
        return;
      }  
   }

   cout<<"sum is not found in the array"<<endl;
}

int main()
{
  int arr[] = {1,2,3,4,5};
  PrintTwoIndexesWhichSumsUptoK(arr, 9);
  return 0;  
}
