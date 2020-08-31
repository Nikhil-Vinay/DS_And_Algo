/* Although it is one of the elementary sorting algorithms with O(n2) worst-case time, insertion sort is 
 * the algorithm of choice either when the data is nearly sorted (because it is adaptive) or when the problem 
 * size is small (because it has low overhead).

For these reasons, and because it is also stable, insertion sort is often used as the recursive base case 
(when the problem size is small) for higher overhead divide-and-conquer sorting algorithms, such as merge sort 
or quick sort */

/* Time complexity calculation - 1 + 2 +3 + 4 + .....n-1 = n*(n-1)/2 ~ o(n2) 
 * Almost same logic for selection and bubble sorting */

/* Insertion sort example card arranging */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void Swap(int &x, int &y)
{
   x = x^y;
   y = x^y;
   x = x^y;
}

void InsertionSort(vector<int> &vct, size_t count)
{
  if(count <= 1)
     return;

  for(int i = 1; i < count; i++) {
     int j = i;
     while(j > 0) {
        if(vct[j] < vct[j-1]) {
           Swap(vct[j], vct[j-1]);
           j = j-1;
        } else {
          break;
        }
     }
  }
}


int main()
{
  vector<int> vct;
  int count = 0;
  cout<<"Please enter the count of numbers" <<endl;
  cin>>count;
  for(int i = 0; i < count; i++) {
    int temp;
    cin>>temp;
    vct.push_back(temp);
  }

  InsertionSort(vct, count);
  cout<<"Sorted array is :"<<endl;
  for(int i = 0; i < count; i++) {
    cout<<vct[i]<<endl;
  }
  return 0;
}
