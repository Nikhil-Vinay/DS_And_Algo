/******** Place odd even numbers at odd even indexes in an array ****************************/

/* An integer array is given, adjust the integers in such a way that odd integers will come at odd index and 
 * even integer will come at even index. If even integers count is greater than total even indexes present in 
 * array then all extra even integers will come in last. Similarly if odd integers count is greater than total
 * indexes present in array then all extra odd integers will come in last.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void Swap(int* arr, int i, int j)
{
  arr[i] = arr[i]^arr[j];
  arr[j] = arr[i]^arr[j];
  arr[i] = arr[i]^arr[j];
}

void NumberPlacement(int* arr, int n)
{
   int even_index = 0;
   int odd_index = 1;

   while(true) {
      while(even_index < n && (arr[even_index]%2 == 0)){
           even_index += 2;
      }

      while(odd_index < n && (arr[odd_index]%2 == 1)){
          odd_index += 2;
      }

      if((even_index < n) && (odd_index < n)) {
         Swap(arr, even_index, odd_index);
         even_index += 2;
         odd_index += 2;
      } else {
         break;
      }
   }
}

void PrintArray(int arr[], int size)
{
  for(int i = 0; i < size; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main()
{
   int arr[] = { 5, 3, 2, 4, 6, 7, 11};
   cout<<"Original array is: "<<endl;
   PrintArray(arr, sizeof(arr)/sizeof(arr[0]));
   NumberPlacement(arr, sizeof(arr)/sizeof(arr[0]));
   cout<<"Final array is: "<<endl;
   PrintArray(arr, sizeof(arr)/sizeof(arr[0]));
   return 0;
}
