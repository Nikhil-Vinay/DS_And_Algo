/****** Find out number of pair of elements which adds equal to a number *************/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void PrintVector(vector<int> &v)
{
  cout<<"Vector elements are: "<<endl;
  for(int i = 0; i < v.size(); i++) {
     cout<<v[i]<<endl;
  }
}

int GetNumOfPair(vector<int> &v, int val)
{
  size_t first = 0;
  size_t last = v.size() - 1;
  int count = 0;
  //  sort the vector first
  sort(v.begin(), v.end());

  while(first < last) {
    if(v[first] + v[last] == val) {
       count++;
       first++;
       last--;
    } else if (v[first] + v[last] < val) {
      first++;
    } else if (v[first] + v[last] > val) {
      last--;
    } 
  }

  return count;
}

int main()
{
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(10);
  v.push_back(5);
  v.push_back(-1);
  v.push_back(6);
  v.push_back(-2);
  v.push_back(1);
  PrintVector(v);
  cout<<"Number of pair which adds to 0 is - "<<GetNumOfPair(v, 0)<<endl;
  return 0;
}
