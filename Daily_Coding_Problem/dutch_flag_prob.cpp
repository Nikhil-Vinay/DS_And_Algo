/*********************** DUTCH FLG PROBLEM ***************************/

/* Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all 
 * the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.
 *
 * Do this in linear time and in-place.
 *
 * For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become 
 * ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
 */

/* Note: There could be a solution as count all three colors and then populate the same array accordingly.
 * This solution is also O(2n) ~ O(n) solution and space complexity is O(3), 3 count variables.
 *
 * But the below solution sorts the array in place in exactly, O(n) time with help of swapping. This solution
 * is very effective in case of big arrays though we need lot of swappings.
 *
 * This problem can occur in many ways as an array of 3 kinds of integers (0, 1, 2) and sort it.
 * This is a very famous problem and this solution works only if three kinds of data present in the array.
 *
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<typename T, size_t N>
void PrintArr(T(&arr)[N])
{
  for(int i = 0; i < N; i++) {
    cout<<arr[i]<<endl;
  }
}

template<typename T, size_t N>
void Swap(T(&arr)[N], int index1, int index2)
{
  arr[index1] = arr[index1]^arr[index2];
  arr[index2] = arr[index1]^arr[index2];
  arr[index1] = arr[index1]^arr[index2]; 
}

template<typename T, size_t N>
void ColorArrange(T(&arr) [N])
{
  int start = 0;      // start index
  int mid = 0;    // mid index
  int last = N-1;   // last index

  while(mid <= last) {
    if(arr[mid] == 'R') {
       Swap(arr, start, mid);
       start++;
       mid++;
    } else if (arr[mid] == 'B') {
       Swap(arr, mid, last);
       last--;
    } else {
      mid++;
    }
  } 
}

int main()
{
  char arr[7] = {'G', 'R', 'B', 'B', 'R', 'B', 'G'};
  PrintArr(arr);
  ColorArrange(arr);
  cout<<"Array after arranging the color: "<<endl;
  PrintArr(arr);
  return 0;
}
