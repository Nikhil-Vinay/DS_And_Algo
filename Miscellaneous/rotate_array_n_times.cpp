/************ Rotate an array left/right by n times *********************************/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

enum rot_dir {
  LEFT,
  RIGHT
};

void PrintVector(vector<int> &v)
{
  for(int i = 0; i < v.size(); i++) {
    cout<<v[i]<< " ";
  }
  cout<<endl;
}

void Reverse(vector<int> &v, int start, int end)
{
  while(start < end) {
    // swap
    v[start] = v[start]^v[end];
    v[end] = v[start]^v[end];
    v[start] = v[start]^v[end];
    start++;
    end--;
  }
}

void RotateVector(vector<int> &v, int rot_count, int rot_dir)
{
  int mid_index = 0;
  if(rot_dir == LEFT) {
     mid_index = v.size() - rot_count;  // get rot_count from end
  } else {
     mid_index = rot_count;             // get rot_count from first
  }

  Reverse(v, 0, mid_index-1);
  Reverse(v, mid_index, v.size()-1);
  Reverse(v, 0, v.size()-1);
}

int main()
{

   vector<int> v;
   for(int i = 1; i < 10; i++) {
      v.push_back(i);
   }
   cout<< "Original Array is - "<<endl;
   PrintVector(v);
   RotateVector(v, 2, LEFT);   
   cout<< "Rotated Array is - "<<endl;
   PrintVector(v);
   return 0;
}
