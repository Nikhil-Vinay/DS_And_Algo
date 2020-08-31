/* There is a road. Along one side of road, there is sequence of vacant plots. Each plot has a different area (non-zero). So the areas form a sequence A[1], A[2]...A[N].
 * You want to buy K acres of land to build a house. You want to find a segment of contiguous plots of minimum length whose sum is exactly k.
 */

/* General question: Find minum length of window of having sum K in an array */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<size_t N>
int MinCountOfSequentialPlots(int (&area) [N], int sum)
{
   int i = 0, j = 0;
   int count = INT_MAX; 
   int temp_sum = 0;

   // Note: here window is not of fixed size
   while(j < N) {
      if(temp_sum + area[j] <= sum) {  // increase right pointer of window
         temp_sum += area[j];
         if(temp_sum == sum) {
            cout<<"position is: "<<i<<" "<<j<<" "<<endl;
            count = min (count, j-i+1);
         }
         j++;
      } else {  // increase left pointer of array to slide the window
        temp_sum -= area[i];
        i++;
      } 
   }

   // Time complexity = while-loop O(N) + i pointer O(N) + j pointer O(N) ~ O(N)

   return count;
}

int main()
{
   int area[8] = { 5, 3, 2, 2, 1, 7, 3, 5 };
   int sum = 10;
   cout<<"Min count of sequential plots: "<<MinCountOfSequentialPlots(area, sum)<<endl;
   return 0;
}
