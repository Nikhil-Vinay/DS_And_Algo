/************* Water trapping problem ***************/
/* There are n buildings in a row of different heights. If it rains water will be accumulated between the buildins during. Find out the maxium water area which can be accumulated, each building width is 1 unit.
 */

/* Soln: Over each building accumulated water area = [min(max building height left side, max building height right side) - current buiding height ]
 *
 * Brute Force: go each index and find highest bar left and right side. O(N^2).
 * Method-1: O(N) time and O(N) space solution: Create/Precomput leftMax and RightMax array which will hold max left and right height at each index.
 *
 * Method-2: O(N) time and O(1) space solution: Instead of maintaing two arrays of size n for storing left and right max of each element, we will just maintain two variables to store the maximum till that point.
 */

#define METHOD1 1
#define METHOD2 0
#include<iostream>
#include<bits/stdc++.h>
#define DEBUG 1

using namespace std;

#if METHOD1
int FindMaxTrappedWater(int* arr, int n)
{
   int* leftMax = new int[n];
   int* rightMax = new int[n];

   // populate array to store left side max building height at each index
   leftMax[0] = arr[0];
   for(int i = 1; i < n; i++) {
      if(arr[i] > leftMax[i-1]) {
         leftMax[i] = arr[i];
      } else {
         leftMax[i] = leftMax[i-1];
      }
   }

   // populate array to store right side max building height at each index
   rightMax[n-1] = arr[n-1];
   for(int i = n-2; i >= 0; i--) {
      if(arr[i] > rightMax[i+1]) {
         rightMax[i] = arr[i];
      } else {
         rightMax[i] = rightMax[i+1];
      }
   }

   // calculate the total water trapping area
   int area = 0;
   int min_of_left_right_max_height = 0;
   for(int i = 0; i < n; i++) {
      min_of_left_right_max_height = min(leftMax[i], rightMax[i]);
      if(min_of_left_right_max_height - arr[i] > 0) {
         area += min_of_left_right_max_height - arr[i];
      }
   }
   
   return area;
}
#endif

#if METHOD2
int FindMaxTrappedWater(int* arr, int n)
{
}
#endif

int main()
{
   int n;
   cout<<"Enter the number of buildings"<<endl;
   cin>>n;
   int *arr = new int [n];
   cout<<"Enter the height of buildings"<<endl;
   for(int i = 0; i < n; i++) {
      cin>>arr[i];
   } 
#if DEBUG
   cout<<"Height of buildings are: "<<endl;
   for(int i = 0; i < n; i++) {
      cout<< arr[i]<< " ";
   }
   cout<<endl;
#endif

   int maxWater = FindMaxTrappedWater(arr, n);
   cout<<"Max trapped water is: "<<maxWater<<endl;

   delete[] arr;
   return 0;
}
