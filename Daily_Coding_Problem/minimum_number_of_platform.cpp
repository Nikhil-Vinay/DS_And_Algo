/***************Find minimum number of platform required for Railway/Bus Station*****************************/

/* Given arrival and departure times of all trains that reach a railway station, find the minimum number of 
 * platforms required for the railway station so that no train waits.
 * We are given two arrays which represent arrival and departure times of trains that stop.
 * Input:  arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
 *         dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
 *         Output: 3
 *         There are at-most three trains at a time (time between 11:00 to 11:20)
 */

/* Variant of this problem:
 * 1. Program Broadcasting Problem:
 *    There are n programs to broadcast and start/end time is given for each program, find out minimum channel to
 *    broadcast all these programs. Programs start/end times can be overlapping.
 *
 * 2. Find Miinmum Number Of Classroom.
 *    There are n classes are to be conducted and start/end time is given for each class, find out minimum number
 *    of class to conduct all the classes. Classes start/end times can be overlapped.
 */


#include<iostream>
#include<bits/stdc++.h>

using namespace std;
// Method - 1  (Time Complexity - O(nlogn) + O(nlogn) + O(2n) ~ O(nlogn)
//
int FindMinumumPlatform1(double *arr, double *dep, int size)
{
  sort(arr, arr+size);   // sort arrival time     O(nlogn)
  sort(dep, dep+size);   // sort departure time   O(nlogn)
  int i = 0, j = 0, k = 0;
  int plat_count[2*size];  // It will store platform count at each point
  // We will increase platform count at arrival and decrease platform count at departure, we'll check arrival
  // departure status from both sorted arrival/departure array as whichever comes first basis.
  // In last, we will iterate through the pat_count array and max value of this array will provide the min
  // platform count needed.
  int n = 0;
  while((i < size) && (j < size)) {
    if(arr[i] < dep[j]) {
       i++;
       n++;
       plat_count[k++] = n;
    } else if (arr[i] > dep[j]) {
      j++;
      n--;
      plat_count[k++] = n;
    } else if (arr[i] == dep[j]) {
      i++;
      j++;
      plat_count[k++] = n;
    }
  }

  // check for resr elements in arr and dep array
  while(i < size){
    n++;
    i++;
    plat_count[k++] = n;    
  }

  while(j < size){
    n--;
    j++;
    plat_count[k++] = n;
  }

  // return the max of plat_count array
  int max = INT_MIN;
  for(i = 0; i < (2*size); i++) {
     if(plat_count[i] > max) {
        max = plat_count[i];
     }
  }

  return max;

}

// Method - 2 (It is very similar to method-1. Here we'll use multimap which is self balanced BST and tales
// O(logn) time for each insertion and stores the elements in default ascending sorted order
// Time complexity of this method - O(nlogn)
//
// We can reduce the time complexity by using unordered_set (c++11 onwards) which is implemented internally
// by hashing mechanism and it takes O(1) time in insetion. So, time for inserting n elements - O(n)
//
// Note: We can use unordered_set and unordered_map at any place where sorting of array is used or set/map is 
// used.

int FindMinumumPlatform2(double* arr, double* dep, int size)
{
   multiset<double> arr_set;
   multiset<double> dep_set;
   for(int i = 0; i < size; i++) {  // each element insertion in set takes O(logn) time.
      arr_set.insert(arr[i]);       // O(nlogn)  // for n elements
      dep_set.insert(dep[i]);       // O(nlogn)  // for n elements
   }

   multiset<double>::iterator it1, it2;

   it1 = arr_set.begin();
   it2 = dep_set.begin();

   int k = 0, n = 0;
   int plat_count[2*size];
   while((it1 != arr_set.end()) && (it2 != dep_set.end())) {
      if(*it1 < *it2) {
         it1++;
         n++;
         plat_count[k++] = n;
      } else if (*it1 > *it2) {
        it2++;
        n--;
        plat_count[k++] = n;
      } else if (*it1 == *it2) {
        it1++;
        it2++;
        plat_count[k++] = n;
      }
   }

   // for rest elements
   while(it1 != arr_set.end()) {
     it1++;
     n++;
     plat_count[k++] = n;
   }

  while(it2 != dep_set.end()) {
     it2++;
     n--;
     plat_count[k++] = n;
  }

  // find max
  int max = INT_MIN;
  for(int i = 0; i < (2*size); i++) {
     if (plat_count[i] > max) {
        max = plat_count[i];
     }
  }

  return max;
}

int main()
{
   double arr[6] = {9.00,  9.40, 9.50,  11.00, 15.00, 18.00};   // arrival time
   double dep[6] = {9.10, 12.00, 11.20, 11.30, 19.00, 20.00};   // departure time

   //int n = FindMinumumPlatform1(arr, dep, sizeof(arr)/sizeof(arr[0]));
   int n = FindMinumumPlatform2(arr, dep, sizeof(arr)/sizeof(arr[0]));

   cout<<"Minimum Number Of Platform Required Is: "<<n<<endl;
   return 0;
}         
