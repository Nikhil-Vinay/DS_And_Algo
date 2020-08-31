/* Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *
 * For example, given [100, 4, 200, 1, 3, 2], the longest consecutive element sequence is [1, 2, 3, 4]. Return its length: 4.
 * */

/* Solution - 1: Sort the array then find lasrgest contiguous substring */

/* Solution -2 : Time complexity O(nlogn),
 * We can achieve time complexity O(n) by unordered-set */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<size_t N>
int findLongestConseqSubseq(int (&arr) [N])
{
   set<int> s;
   // insert all elements in set
   for(int i = 0; i < N; i++) {
      s.insert(arr[i]);
   }
  
   int max_len = INT_MIN;

   for(int i = 0; i < N; i++) {
      if(s.find(arr[i]-1) == s.end()) {  // if element is first element of sequence
         int j = 1;
         while(s.find(arr[i]+j) != s.end()) {
            j++;
         }
         max_len = max(max_len, j);
      }   
   }

   return max_len;
}

int main()
{
   int arr[] =  {11, 1, 9, 3, 10, 4, 20, 2};
   cout<<findLongestConseqSubseq(arr)<<endl;
   return 0;
}
