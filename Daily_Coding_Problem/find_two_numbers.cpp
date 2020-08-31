/************ Prob-1 (Easy): FInd two numbers in an array **************************/

/* There could be multiple form of this question as :
 * 1. Find two numbers in an array whose sum is x.
 * 2. Find if two equal numbers are present in array.
 * 3. so on...
 *
 * A simple solution of this kind of question is to sort the array and find out (time complexity - O(NlogN).
 * Brute force time complexity is - O(N2)
 *
 * Solution:
 * 1. sort the array and set two pointers at array_start and array_end. Check the sum of values at two pointers
 *     and accordingly increase/decrease pointers.
 * 2. Sort the array and traverse the array from start to end.
 *
 */

/* Now to reduce the time complexity to O(N), we will use hasing. It will increase the space complexity to O(N)
 * but reduce the time complexity to - O(N) from O(NlogN).
 *
 * Note: we can apply this method on finding three numbers and finding four numbers prob also to reduce time 
 * complexity.
 */

/* For hasing we can use unordered_set or unordered_map */

#include<bits/stdc++.h>
#include<iostream>

using namespace std;
// Method-1
#if 1
// Time complexity - O(nlogn)
void PrintTwoNumbersEqualToSum(vector<int> &vct, int size, int sum) 
{
  //qsort((void*)vct, size, sizeof(int));  //nlogn, worst case C++03 time complexity - O(n2), average - O(nlogn)
  int first = 0, last = size-1;
  sort(vct.begin(), vct.end());  // nlogn
  while(first < last) {
      if(vct[first] +  vct[last] == sum) {
        cout<<"Numbers are: "<<vct[first]<<" and "<<vct[last]<<endl;
        break;
      } else if ((vct[first]+vct[last]) < sum) {
        first++;
      } else {
        last--;
      }
   } 
}
#endif

#if 0
// Time complexity - O(N), space complexity - O(N)
void PrintTwoNumbersEqualToSum(vector<int> &vct, int size, int sum)
{
  unordered_map<int> mymap;   // implemented by hashing, seach and insertion is O(1)
                              // c++11 is not suported here
  for(int i = 0; i < size; i++) {
    if(mymap.find(sum-vct[i]) != mymap.end()) {
      cout<<"Found Two Numbers are: "<<vct[i]<<" and "<<sum-vct[i]<<endl;
      break;
    }
  }
}

#endif
int main()
{

  int arr[5] = { 10, 5, 2, 40, 7 };
  vector<int> vct(arr, arr+5);
  
  PrintTwoNumbersEqualToSum(vct, vct.size(), 45);
  return 0;
} 
