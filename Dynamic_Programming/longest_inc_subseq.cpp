/********* Find out length of longest increasing subsequence of an array ********************/
/* Example: arr[] = { 1, 5, 3, 2, 8, 4, 10, 12 } , LIC length = 5 , { 1, 5, 8, 10, 12} or { 1, 3, 8, 10, 12 }
 *
 * Box stacking problem is based on this only (asked in samsung). 
 */

/* Variant of this problem: 
 * 1. Find minimum number of element to delete from an array to make an array sorted in ascending order.
 *    Minimum number of elements to delete for making array sorted = array size - LIS length
 *
 * 2. The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
 *    dir
 *      subdir1
 *      subdir2
 *         file.ext
 *
 *   The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir22\n\t\tsubsubdir2\n\t\t\tfile2.ext
 *   dir
 *     subdir1
 *       file1.ext
 *       subsubdir1
 *     subdir2
 *       subsubdir2
 *         file2.ext
 *
 *  Find the longest(number of characters) absolute path to a file within our filesystem. For the above example,
 *  the longest absolute path is: "dir/subdir2/subsubdir2/file2.ext" and its length is 32(without quotes).
 *  If there is no file in the system, return zero.
 *  This problem was asked by Google.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int GetLISLength(int* arr, int n)
{
  int* tmp = new int(n);
  // at every index, minimum substring length is 1
  // tmp array will have max length of increasing substr at corresponding to every index.
  for (int i = 0; i < n; i++) {
       tmp[i] = 1;
  }
  
  int i = 1;
  
  while(i < n) {
      // compare from just previous element in case of increasing elements
      //if(arr[i] >= arr[i-1]) {
      //   tmp[i] = tmp[i-1] + 1;
      //} else {
         // if next element is non increasing, compare with all previous elements
         for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
               if((tmp[j] + 1) > tmp[i]) {
                  tmp[i] = tmp[j] + 1;
               }
            }
         }
      //}
      i++; 
  }

  // find the max substr length
  int maxlen = 0;
  for(int i = 0; i < n; i++) {
    if (tmp[i] > maxlen) {
        maxlen = tmp[i];
    }  
  }

  return maxlen;
}

int main()
{

  int arr[8] = { 1, 5, 3, 2, 8, 4, 10, 12 };
  //int arr[4] = { 1, 2, 0, 3};
  cout<<" Length of longest increasing subsequence is: "<<GetLISLength(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
  return 0;
}
