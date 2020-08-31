/****************** Find highest multiple of threee numbers in an array ***************************/

/*** Example: if the list is [-10, -10, 5, 2], we should return 500, since that's -10 * -10 * 5 **/

/* Note: It's a a beautiful problem, the solution trick can be applied on other variant as find highest addition
 * of three numbers in an array ***/

/* Soln-1: Sort the array and multiply the biggest three. O(nlogn) */

/* Soln-2: Create 4 arrays LeftMin, LeftMax, RightMin and RightMax.
 *         LeftMin[i] will have min element from 0 to i-1 in original array.
 *         LeftMax[i] will have min element from 0 to i-1 in original array.
 *         RightMin[i] will have min element from i+1 to n-1 in original array.
 *         RightMax[i] will have max element from i+1 to n-1 in original array.
 *  
 *  Then, for each index in range { 1 to n-2 }, find max((arr[i]*LeftMin[i]*RightMin[i]), (arr[i]*LeftMin[i]*
 *  RightMax[i]), (arr[i]*LeftMax[i]*RightMin[i]), (arr[i]*LeftMax[i]*RightMax[i]))
 *
 *  Time complexity - O(n)
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<size_t N>
int GetMaxMult(int (&arr)[N])
{
   if(N < 3) {
     return -1;
   }

   vector<int> LeftMin;
   vector<int> LeftMax;
   vector<int> RightMin;
   vector<int> RightMax;
   LeftMin.resize(N);
   LeftMax.resize(N);
   RightMin.resize(N);
   RightMax.resize(N);

   // Populate LeftMin and LeftMax
   int minval = INT_MAX;
   int maxval = INT_MIN;
   for(int i = 1; i < N; i++) {
      if(arr[i-1] < minval) {
        minval = arr[i-1];  
      }
      LeftMin[i] = minval;

      if(arr[i-1] > maxval) {
         maxval = arr[i-1];
      }
      LeftMax[i] = maxval;
   }

   // Populate RIghtMin  and RightMax
   minval = INT_MAX;
   maxval = INT_MIN;
   for(int i = N-2; i >= 0; i--) {
      if(arr[i+1] < minval) {
        minval = arr[i+1];
      }
      RightMin[i] = minval;

      if(arr[i+1] > maxval) {
        maxval = arr[i+1];
      }
      RightMax[i] = maxval;
   }

   int multmax = INT_MIN;
   for(int i = 1; i < N-1; i++) {
      int max1 = max((arr[i]*LeftMin[i]*RightMin[i]), (arr[i]*LeftMin[i]*RightMax[i]));
      int max2 = max((arr[i]*LeftMax[i]*RightMin[i]), (arr[i]*LeftMax[i]*RightMax[i]));
      multmax = max(multmax, max(max1, max2)); 
   }

   return multmax;
}

int main()
{
  int arr[4] = {-10, -10, 5, 2};

  int maxval = 0;
  if ((maxval = GetMaxMult(arr)) == -1) {
     cout<<"Array has less than 3 elements"<<endl;
  } else {
     cout<<"Max multiplication of 3 elements are: "<<maxval<<endl;
  }

  return 0;
}     
