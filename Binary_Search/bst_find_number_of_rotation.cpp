/**************** Find number of rotation in rotated sorted array ************************/
/* Example : 
   int arr[7] = {35, 40, 90, 100, 10, 20, 30};  // rotated sorted array - 10, 20, 30, 35, 40, 90, 100
   Trick: Number of rotation = number of elements before smalles number in array
                             = index of smallest number in array

  Constraint of this problem there shouldn't be any duplicate number.

*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<size_t N>
int get_least_number_index(int (&arr)[N], int start, int end)
{
  if(start > end) {
    return -1;  // not properly sorted or rotated
  } 

  int mid = (start + (end - start)/2);  // taking care of if start+end will be big number

  // if sorted array is rotated then least number will have greater number in right and left
  // take modulus by N for mid+1 to avoid access of out of bound array
  // take modulus after adding N for mid-1 to avoid access of negative index 
  if(arr[mid] < arr[(mid-1+N)%N] && arr[mid] < arr[(mid+1)%N]) {
    return mid;
  }
 
  // one half will always be sorted
  // we are cutting the array half in all the four scenarios, so time complexity is O(logn)
  // taking advantage of rotated but sorted array
  // Trick is: one half will be always sorted
  if(arr[start] < arr[mid]) { // left half is properly sorted and arr[mid] is not least then discard lef half
     return get_least_number_index(arr, mid, end);
  } else if (arr[mid] < arr[end]) { // right half is properly sorted and arr[mid] is not least then discard
     return get_least_number_index(arr, start, mid);  // right half
  }                                       
}

int main()
{
   int arr[7] = {35, 40, 90, 100, 10, 20, 30};  // rotated sorted array - 10, 10, 20, 30, 35, 40, 90, 100
   int number;
   cout<<"Array is as below: "<<endl;
   for(int i = 0; i < sizeof(arr)/sizeof(*arr); i++) {
      cout<<arr[i]<<" ";
   }
   cout<<endl;
   cout<<"Number of rotation in sorted array: "<<get_least_number_index(arr, 0, (sizeof(arr)/sizeof(*arr))-1)<<endl;
   return 0;
}
