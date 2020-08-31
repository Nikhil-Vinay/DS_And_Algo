#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void updateTree(int* arr, int* BIT, int n, int index, int val) 
{
   arr[index] = val;
   for(; index <= n; index += (index & (-index))) {
      BIT[index] ^= val;
   }
}

int query (int* BIT, int index)
{
   int sum = 0;
   for(; index > 0; index -= (index & (-index))) {
       sum += BIT[index];
   }
   return sum;
}

int main()
{
   int n;
   cout<<"Enter the number of elements of array: "<<endl;
   cin>>n;
   
   // default construtor will initialize all elements by zero
   int* arr = new int[n+1]();
   int* BIT = new int[n+1]();
   for(int i = 1; i <= n; i++) {
     int num;
     cin>>num;
     updateTree(arr, BIT, n, i, num);
   }

   cout<<"Sum of range from index 0 to index 5 : "<< query(BIT, 5)<<endl;
   cout<<"Sum of range from index 2 to index 6 : "<< query(BIT, 6) - query(BIT, 1)<<endl;

   // Note: current 1 is at index 1 in array. If we want to update with 5 at index 1
   // Here it is different from segment tree, previous value(1) is distributed between nodes
   // so, if we will directly update as below then it will additionaly distribute with new val (5)
   // to respective nodes so, effectively total value at index(1) will become (1+5 = 6)
   // updateTree(arr, BIT, n , 1, 5)  // wont work
   //
   // So, we can update in different way as: first remove previous value then add new value as below:
   // updateTree(arr, BIT, n, 1, -arr[1]);
   // updateTree(arr, BIT, n, 1, 5);
   //
   // Or we can updat with relative value of new value from previus value as below:
   // updateTree(arr, BIT, n, 1, 5-arr[1])

   updateTree(arr, BIT, n , 1, 5-arr[1]);  // update index 1 with 5
   cout<<"Sum of range from index 0 to index 5 after update : "<< query(BIT, 5)<<endl;
   
   return 0;
}
