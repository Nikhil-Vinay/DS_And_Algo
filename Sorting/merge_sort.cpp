/********************* Merge Sort ****************************/
/*  Time Complexity - O(nlogn)
 *  Beauty - Merge two sorted array
 *
 *  Merge sort is often preferred for sorting a linked list.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &vct, size_t low, size_t high)
{
  size_t mid = (low+high)/2;
  vector<int> tmpvct;
  size_t left_low_index = low;
  size_t right_low_index = mid+1;
  while(left_low_index <= mid && right_low_index <= high) {
    if(vct[left_low_index] <= vct[right_low_index]) {
       tmpvct.push_back(vct[left_low_index++]);
    } else {
       tmpvct.push_back(vct[right_low_index++]);
    }
  }

   // Insert rest elements
   while(left_low_index <= mid) {
      tmpvct.push_back(vct[left_low_index++]);
   }

   while(right_low_index <= high) {
      tmpvct.push_back(vct[right_low_index++]);
   }

   // Copy tmpvct to orig vct
   int j = 0;
   for(size_t i = low; (i <= high && j < tmpvct.size()); i++, j++)
   {
     vct[i] = tmpvct[j]; 
   }
}

void mergeSort(vector<int> &vct, size_t low, size_t high)
{
   if(low == high || low > high) {
      return;
   }
   size_t mid = (low+high)/2;
   mergeSort(vct, low, mid);
   mergeSort(vct, mid+1, high);
   merge(vct, low, high);
}

int main()
{
  int count;
  vector<int> vct;
  cout<< "Please enter the count of numbers" <<endl;
  cin >> count;
  for (int i = 0; i < count; i++) {
     int temp;
     cin>>temp;
     vct.push_back(temp);
  }
  
  mergeSort(vct, 0, count-1);
  // Print sorted array
  cout<<"Sorted array is: "<<endl;
  for(int i = 0; i < count; i++) {
    cout << vct[i]<<endl;
  }
  return 0;
}
