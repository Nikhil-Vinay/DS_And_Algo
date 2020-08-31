/******** TIme complexity is O(nlogn) but space complexity is better than merge sort, it doesn't use additional
 *  array to merge the two sorted arrays */
/* qsort in C language is implemented as same */
/* void qsort (void* base, size_t num, size_t size, 
 *             int (*comparator)(const void*, const void*)) */
/* C++ sorting STL algorithm is not quick sort, thats some hybrid algorithm */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void Swap(vector<int> &vct, int i, int j)
{
  if(i == j)
     return;
  // if i and j are same then below logic will not work
  vct[i] = vct[i]^vct[j];
  vct[j] = vct[i]^vct[j];
  vct[i] = vct[i]^vct[j];
}

int Partition(vector<int> &vct, int start, int end)
{
   int i = start+1;
   int pivot_element = vct[start]; //make the first element as pivot element
   /*rearrange the array by putting elements which are less than pivot
     on one side and which are greater that on other. */
   for(int j = start+1; j <= end; j++) {
      if(pivot_element > vct[j]) {
         Swap(vct, i, j);
         i += 1;        
      }
   }
   //put the pivot element in its proper place.
   Swap(vct, start, i-1);
   // return the position of pivot
   return i-1;
   
}

void QuickSort(vector<int> &vct, int start, int end)
{
   if(start == end || start > end) {
      return;
   }
   int partition_pivot = Partition(vct, start, end);
   QuickSort(vct, start, partition_pivot-1);  // very imp, sort the left side of pivot
   QuickSort(vct, partition_pivot+1, end);    // very imp, sort the right side of pivot
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

  QuickSort(vct, 0, count-1);
  cout<<"Sorted array is :"<<endl;
  for(int i = 0; i < count; i++) {
    cout<<vct[i]<<endl;
  }
  return 0;
}
