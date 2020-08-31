/*** There are n contigious numbers from 1...N in an array, two numbers are missing out of them, find out that */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/* Method - 1 :
 * First find the addition of two missing numbers = A.P sum [1..N] - total_arr_sum
 * Find middle number of two missing numbers = mid = (sum of two missing numbers)/2;
 * Now find first missing number between [1...mid] and second missing number in [mid+1....N]
 * Time complexity is O(N).
 * This method is proper if numbers are in perticular order, A.P, G.P, H.P or hybrid of any as A.P+G.P etc.
 */

vector<int> FindNumbers(vector<int> arr)
{
   vector<int> vct;
   int size = arr.size();
   int tot_sum = (size+2)*(size+3)/2;
   int arr_sum = 0;
   for(int i =0; i < size; i++) {
      arr_sum += arr[i];
   }
   int two_num_sum = tot_sum - arr_sum;
   int mid = two_num_sum/2;

   // first missing number is between first_range_sum [1..mid], second missing number is between 
   // second_range_sum [mid+1..N]
   int missing = 0;
   int first_range_sum = 0;
   int second_range_sum = 0;

   for(int i = 0; i < size; i++) {
      if(arr[i] <= mid) {
         first_range_sum += arr[i];
      } else {
         second_range_sum += arr[i];
      }
   }

   int first_missing_number = (mid * (mid+1))/2 - first_range_sum;
   int second_missing_number =  tot_sum - (mid*(mid+1))/2 - second_range_sum;

   vct.push_back(first_missing_number);
   vct.push_back(second_missing_number);

   return vct;
}


int main()
{
  int n = 10;
  vector<int> arr;  // 4 and 9 are missing
  arr.push_back(1);
  arr.push_back(5);
  arr.push_back(6);
  arr.push_back(3);
  arr.push_back(2);
  arr.push_back(8);
  arr.push_back(10);
  arr.push_back(7);

  vector<int> vct = FindNumbers(arr);
  cout<<"Missing Numbers are: "<<endl;
  for(int i = 0; i < vct.size(); i++) {
     cout<<vct[i]<<endl;
  }
  return 0;
}
