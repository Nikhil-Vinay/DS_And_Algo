/* Given a list of possibly overlapping intervals, return a new list of intervals where all overlapping intervals have been merged.
 *
 * The input list is not necessarily ordered in any way.
 *
 * For example, given [(1, 3), (5, 8), (4, 10), (20, 25)], you should return [(1, 3), (4, 10), (20, 25)].
 * [(1,3), (2,4), (5,7), (6,8)], you should return [(1,4), (5,8)]
 */
/* Time complexity - O(nlogn) */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class interval
{
  public:
  int start;
  int end;
  interval(int x, int y): start(x), end(y) { }
};

class mycomp
{
  public:
  bool operator() (const interval &a, const interval &b)
  {
    return a.start < b.start;
  }
};

int main()
{
  int n;
  vector<interval> vct;
  cout<<"Provide count of the intervals: "<<endl;
  cin >> n; 
  int i = 1;
  while(i <= n) {
    int start, end;
    cout<<"Provide start and end of interval-"<<i<<endl;
    cin>>start>>end;
    vct.push_back(interval(start, end));   
    i++;
  }

  sort(vct.begin(), vct.end(), mycomp());  // nlongn
  
  vector<interval> res_vct;
  int start = vct[0].start, end = vct[0].end;
  i = 1;
  while (i < n) {
     if((vct[i].start < end) && (vct[i].end > end)) {
       end = vct[i].end;
     } else if ((vct[i].start <= end) && (vct[i].end <= end)) {
       // no need to do anything
     } else {
       res_vct.push_back(interval(start, end));
       start = vct[i].start;
       end = vct[i].end; 
     }
     i++;
  }
  
  // check for last one
  int res_vct_size = res_vct.size();
  if((res_vct[res_vct_size-1].start != vct[n-1].start) &&
     (res_vct[res_vct_size-1].end != vct[n-1].end)) {
     res_vct.push_back(interval(start, end));
  }

  // print result interval
  cout<<"Result Intervals Are: "<<endl;
  for (int i = 0; i < res_vct.size(); i++) {
    cout<<"("<<res_vct[i].start<<","<<res_vct[i].end<<")"<<endl;
  }
  return 0;
}
