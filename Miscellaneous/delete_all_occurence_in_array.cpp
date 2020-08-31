/*** Delete all occurence of an element from an array ********************/
/*** Array is storage of contiguous memory, so trivial solution of this prob is, array is iterated 0 to N and 
 * wherever it will find the element, it needs to remove it. It will have O(n2) time complexity because
 * after deleting one element whole array element needs to be shifted. In worst case for each element shifting
 * will happen then time complexity is - 1 + 2 + 3....n-1 =  n*(n-1)/2 ~ O(n2).
 */

/* The below is best time complexity solution - O(n), Here we shift all occurence of element on right side of
 * array and finally we reduce the size of the array.
 * std::remove(vec.bigin(), vec.end(), val)  has the same implementation */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void PrintArr(int arr[], int len) 
{
  for(int i = 0; i < len; i++) {
     cout<<arr[i]<<endl;
  }
}

int DeleteElement(int arr[], int len, int val)
{
  int first = 0;
  int last = len - 1;
  while(first < last && first < len && last >= 0) {
     if(arr[first] == val) {
        while(arr[last] == val && last >= 0) {
           last--;
        }
        if(last >= 0 && arr[last] != val) {
           // swap
           arr[first] = arr[first]^arr[last];
           arr[last] = arr[first]^arr[last];
           arr[first] = arr[first]^arr[last];
        }
     }
     first++;
  }

  int delcount = 0; 
  for(int i = len-1; i >= 0; i--) {
    if(arr[i] == val) {
       delcount++;
    }
  }
  return len - delcount;
}

int main()
{

   //int arr[6] = { 5 , 5, 2, 3 ,4, 5 };
   int arr[6] = { 5 , 5, 5, 5 ,5, 5 };
   int len = sizeof(arr)/ sizeof(arr[0]);
   cout<<"Array size is "<<len<<endl;
   cout<<"Array before deletion is "<<endl;
   PrintArr(arr, len);
   len = DeleteElement(arr, len, 5);
   cout<<"Array size after deletion is "<<len<<endl;
   cout<<"Array after deletion is "<<endl;
   PrintArr(arr, len);

   return 0;
}
