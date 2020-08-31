#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<size_t N>
bool rotated_binary_search(int (&arr)[N], int number, int start, int end)
{
  if(start > end) {
    return false;  // not found
  } 

  int mid = (start + (end - start)/2);  // taking care of if start+end will be big number

  if(number == arr[start] || number == arr[end] || number == arr[mid]) {
    return true;
  }

  // one half will always be sorted
  // we are cutting the array half in all the four scenarios, so time complexity is O(logn)
  // taking advantage of rotated but sorted array
  // Trick is: one half will be always sorted
  if(arr[start] < arr[mid]) { // left half is properly sorted
     if(number > arr[start] && number < arr[mid]) {
        return rotated_binary_search(arr, number, start+1, mid-1);
     } else {
        return rotated_binary_search(arr, number, mid+1, end-1);
     }
  } else if (arr[mid] < arr[end]) { // right half is properly sorted
     if(number > arr[mid] && number < arr[end]) {
        return rotated_binary_search(arr, number, mid+1, end-1);
     } else {
        return rotated_binary_search(arr, number, start+1, mid-1);
     }
  }
}

int main()
{
   //int arr[7] = {35, 40, 90, 100, 10, 20, 30};  // rotated sorted array - 10, 20, 30, 35, 40, 90, 100
   int arr[7] = {4, 5, 6, 7, 0, 1, 2};  // rotated sorted array - 10, 20, 30, 35, 40, 90, 100
   int number;
   cout<<"Array is as below: "<<endl;
   for(int i = 0; i < sizeof(arr)/sizeof(*arr); i++) {
      cout<<arr[i]<<" ";
   }
   cout<<endl;
   cout<<"Please enter the number to search"<<endl;
   cin >> number;
   if(rotated_binary_search(arr, number, 0, sizeof(arr)/sizeof(*arr))) {
     cout<<"Entered element is found"<<endl;
   } else {
     cout<<"Entered element is not found"<<endl;
   }
   return 0;
}
