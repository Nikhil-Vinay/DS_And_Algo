/********** Find subset of an array which add upto k (Google) ***************************/

/*Given a list of integers S and a target number k, write a function that returns a subset of S that adds up to k. If such a subset cannot be made, then return null.
 *
 * Integers can appear more than once in the list. You may assume all numbers in the list are positive.
 *
 * For example, given S = [12, 1, 61, 5, 9, 2] and k = 24, return [12, 9, 2, 1] since it sums up to 24
 *
 */

#include<iostream>
#include<bits/stdc++.h>
#define DEBUG 0

using namespace std;

template<size_t N>
void PrintSubsetUtil(int(&arr)[N], int** table, int sum, int index, vector<int> &vct)
{
   // base condition
   if(sum == 0) {
      cout<<"Subset is: { ";
      for(int i = 0; i < vct.size(); i++) {
          cout<<vct[i]<<", ";
      }
      cout<<"}"<<endl;
      return;
    } 

    if(sum < 0 || index < 0) {
      return;
    }  

   if(arr[index-1] > sum) {
     // we have excluded arr[n-1] in this case
     PrintSubsetUtil(arr, table, sum, index-1, vct);
   } else {
     // need to check whether this element has included or excluded
     // if inclusion and exclusion both will be 1 means multiple subset possible, we need to call for both cases
     if(table[index-1][sum]) {  // for exclusion
       PrintSubsetUtil(arr, table, sum, index-1, vct);
     }

     if(table[index-1][sum - arr[index-1]]){  // for inclusion
       vct.push_back(arr[index-1]);
       PrintSubsetUtil(arr, table, sum-arr[index-1], index-1, vct);
     }
   }
}

template<size_t N>
void FindSubset(int(&arr)[N], int sum)
{
  int** table;
  table = new int*[N+1];
  for(int i = 0; i <= N; i++) {
     table[i] = new int[sum+1];
  }
  // solve for whether we array has a subset of given sum or not (include/exclude method)
  // rows will represent the array elements and columns awill represent the required sum
  for(int i = 0; i <= N; i++) {
     table[i][0] = 1;   // is sum is zero then we can find it with any elemnts of array so first column is 1
  }

  for(int j = 1; j <= sum; j++) {
     table[0][j] = 0;   // if array doesn't have any element, subset can't be found with any sum
  }

  // fill rest of the table
  for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= sum; j++) {
          if(arr[i-1] > j) {
             table[i][j] = table[i-1][j];  // exclude
          } else {
             int exclude = table[i-1][j];
             int include = 0;
             if((j - arr[i-1]) >= 0) {
                include = table[i-1][j-arr[i-1]];
             }
             table[i][j] = include || exclude;  // include or exclue
          }
      }
  }

#if DEBUG
  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= sum; j++) {
       cout<<table[i][j]<< " ";
    }
    cout<<endl;
  }
#endif

  if(table[N][sum] == 1) {
     cout<<"Possible"<<endl;
     vector<int> subset;
     PrintSubsetUtil(arr, table, sum, N, subset);
  } else {
     cout<<"Not Possible"<<endl;
  }
}

int main()
{
  int arr[6] = { 12, 1, 61, 5, 9, 2 };
  //int arr[3] = { 1, 3, 7 };
  //int sum = 66;
  int sum = 24;
  //int sum = 8;
  FindSubset(arr, sum);
  return 0;
}
