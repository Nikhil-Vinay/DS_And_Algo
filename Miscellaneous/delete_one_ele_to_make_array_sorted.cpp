/************* If an array is given then after removing any single element array should be sorted.
 * How many ways are possible */

/*   Example: 1 2 3 4 5 4 6
 *   Output 2
 *   [ 1 2 3 4 4 6] // after removing 5
 *   [ 1 2 3 4 5 6] // after removing 4
 */

/* This is a very beautiful question. if we look closely, answer could be only 0 or 1 or 2 or n.
 * case 1: If array is fully sorted then then n ways to remove single element to make array sorted. we can remove
 *         each element once.
 * case 2: While traversing if we find decresing element at index i, then we check if removing element at 
 *         index (i-1), makes array sorted till index i. In this case one solution is removing index at i will
 *         make array sorted till i so, till index i number of ways = 1. Now, if second check also works as 
 *         removing element at index (i-1) makes array sorted till index i then till index i, number of ways = 2.
 *         once this condition meets we need to check from i+1 to n. all elements should be in ascending order
 *         from i+1 to n else number os ways will be zero.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int NumOfWays(int* arr, int n)
{
  bool found_decreasing = false;
  int num_of_ways = 0;
  int i = 1;
  while(i < n) {
    if (arr[i] < arr[i-1]) {
       found_decreasing = true;
       // by removing current element, check for rest elements
       num_of_ways = 1;
       for(int j = i+1; j < n; j++) {
          if(arr[j] < arr[i-1]) {
             num_of_ways = 0;
             break;
          }
       }
       
       num_of_ways++;

       if((i >= 2) && (arr[i] >= arr[i-2])) { // by removing left element
          // check for rest elements
          for (int j = i+1; j < n; j++) {
              if (arr[j] < arr[i]) {
                 num_of_ways--;
                 break;
              }
           }
        }
      }
      i++;
    }

    if(found_decreasing == false) {
       return n;
    }

    if(num_of_ways > 0) {
      return num_of_ways;
    }

    return 0;
}
int main()
{ 
   int arr[7] = {1, 2, 3, 4, 5, 4, 6 };
   cout<<"Number of ways to delete one element to make array sorted is: "<<NumOfWays(arr, sizeof(arr)/sizeof(arr[0]))<<endl;

   return 0;
}
