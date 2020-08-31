/***************** Ternary Search *********************************************/

/* Note: It is similar to binary search and applied on sorted array only ********/

/** Time complexity is O(log3N).
 * Below solution is recursive solution.
 * We can solve it iteratively also.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int TernarySearch(vector<int> &vct, int element, int start, int end)
{
  if(start == end) {
     if(vct[start] == element) {
        return 1;
     } else {
        return 0;
     }
  }

  if(start > end ) {
    return 0;
  }

  int mid1 = start  + (end - start)/3;
  int mid2 = end - (end - start)/3; 

  if((element == vct[start]) || (element == vct[end]) || (element == vct[mid1]) ||
     (element == vct[mid2])) {
     return 1;
  }

  if(element > mid2) {
    return TernarySearch(vct, element, mid2+1, end-1);
  } else if (element < mid1) {
    return TernarySearch(vct, element, start+1, mid1-1);
  } else {
    return TernarySearch(vct, element, mid1+1, mid2-1);
  }
}

int main()
{
  int arr[10] = { 1, 6, 3, 5, 4, 8, 9, 2, 7, 10 };
  vector<int> vct(arr, arr+10);
  sort(vct.begin(), vct.end());
  int element;
  cout<<"Please enter the element to search:"<<endl;
  cin>>element;
  int found = TernarySearch(vct, element, 0, vct.size()-1);
  if(found == 0) {
    cout<<"element is not found"<<endl;
  } else {
    cout<<"element is found"<<endl;
  }
  return 0; 
}
