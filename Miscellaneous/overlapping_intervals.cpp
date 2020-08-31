/* Given a collection of Intervals,merge all the overlapping Intervals.
 * For example:
 *
 * Given [1,3], [2,6], [8,10], [15,18],
 *
 * return [1,6], [8,10], [15,18].
 *
 * Make sure the returned intervals are sorted.
 */

#include<iostream>
#include<bits/stdc++.h>
#define DEBUG 1

using namespace std;

void MergeOverlappingIntervals(vector<pair<int, int> > &interval_arr)
{
   if(interval_arr.size() == 0) {
     return;
   }
   vector <pair<int, int> >::iterator it;
   // first sort the vector, sort is done by pairObj->first, if pairObj->first is equal then sort is done by
   // pairObj->second
   sort(interval_arr.begin(), interval_arr.end());
#if DEBUG
   cout<<"Sorted intervals are: "<<endl;
   for(it = interval_arr.begin(); it != interval_arr.end(); it++) {
      cout<<it->first<<"  "<<it->second<<endl;
   }
#endif
   vector<pair<int, int> > output;
   for(it = interval_arr.begin(); it != interval_arr.end(); it++) {
       if(it == interval_arr.begin()) {
          output.push_back(*it);
       } else {
          if(it->first < output.back().second) {
             output.back().second = it->second;
          } else {
             output.push_back(*it);
          }
       }
   }

   cout<<"Merged overlapping intervals are: "<<endl;
   for(it = output.begin(); it != output.end(); it++) {
      cout<<it->first<<"  "<<it->second<<endl;
   }
   
}

int main()
{
   int n;
   cout<<"Enter the number of intervals."<<endl;
   cin>>n;
   vector <pair<int, int> > interval_arr;
   int i = 0;
   cout<<"Enter the "<<n<<" intervals: "<<endl;
   while(i < n)
   {
     pair<int, int> tmp_pair;
     cin>>tmp_pair.first>>tmp_pair.second;
     interval_arr.push_back(tmp_pair);
     i++; 
   }
#if DEBUG
   cout<<"Entered intervals are: "<<endl;
   vector <pair<int, int> >::iterator it;
   for(it = interval_arr.begin(); it != interval_arr.end(); it++) {
      cout<<it->first<<"  "<<it->second<<endl;
   }
#endif

   MergeOverlappingIntervals(interval_arr);
   return 0;
}
