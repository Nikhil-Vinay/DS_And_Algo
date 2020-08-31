/*********************** Binary search *********************************/
/* Binary search is always performed in sorted array else sorting itself will take O(NlogN) which is worst than
 * linear serach of O(N).
 * Binary search in a sorted array takes O(logN) time in worst case.
 *
 * Binary search in BST takes O(N) time in worst case if tree has all nodes right sided or left sided.
 * So, get rid of this prob, we go with self balanced BST as AVL tree which is always balanced by L-L, R-R, L-R,    R-L rotation but here each node size increases an addition integer element - height.
 * Rotation is also costly so we go with red-black tree. Red -black tree also performs rotation to balance
 * itself but here number of rotaion is less compared to AVL tree because of som set of rules for red and black
 * marked nodes. */

/* Note: Below implementation is best optimized code of binary search.
 * Somewhere, it is as if mid is not matching with value then they call BSUtil on (mid, end) & (0, mid-1).
 * Somewhere, it is as if mid is not matching with value then they call BSUtil on (mid+1, end) & (0, mid-1)
 * Best way is we have start, end and mid in each iteration so, check with all three if value matches else
 * exclude all three from next iteration. */


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool BSUtil(vector<int> &vct, int start, int end, int val)
{
   if(end < start) {
      return false;
   }
      
   int mid = start + (end-start)/2;   // protect integer overflow
   if(vct[mid] == val || vct[start] == val || vct[end] == val) {
     return true;
   } else if (vct[mid] > val) {
     return BSUtil(vct, start+1, mid-1, val);
   } else {
     return BSUtil(vct, mid+1, end-1, val);
   }
}

bool BinarySearch(vector<int> &vct, int val)
{
   sort(vct.begin(), vct.end());
   return BSUtil(vct, 0, vct.size(), val);  
}

int main() 
{
  int n;
  cout<<"Please eneter the counts of number: "<<endl;
  cin>> n;
  vector<int> vct;
  while(n--) {
    int tmp;
    cin >> tmp;
    vct.push_back(tmp);
  }

  int val;
  cout<<"Please enter the number to search: "<<endl;
  cin >> val;
  cout<<"element is "<<(BinarySearch(vct, val)?"found":"not found")<<endl;
  return 0;
}
