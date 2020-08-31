/* There is a given array of size of n, maximize the sum of the array after incerting sign of texact k elements*//* Example: Array: [10, 2, 6, -3, -2, 15, 1]  // n = 7, k = 4
   We need to invert the sign of k(4) elements to maximize the total sum of array.
   Soln: iterate k times and always pick smallest one and then revrt the sign (positive to negative and vice versa */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int MaximizeArraySum(vector<int> &vct, int k)
{
   // method-1: iterate k times and find min element in each iteration and invert the sign O(nk)
   // imethod-2; We will use heap here as heapifying of an array takes O(n) time.

   // we are solving my method-1 here
   vector<int>::iterator it;
   for(int i = 0; i < k; i++) {
      int idx = min_element(vct.begin(), vct.end()) - vct.begin();
      cout<<"reverting at index: "<<idx<<" "<<vct[idx]<<endl;
      vct[idx] = -vct[idx];
   }

   // print vector
   //for(int i = 0; i < vct.size(); i++) {
   //  cout<<vct[i]<<endl;
   //}
   int sum = 0;
   int tot_sum = accumulate(vct.begin(), vct.end(), sum);
   return tot_sum;
}

int main()
{
  int n;
  int k;
  cout<<"Enter the size of the array"<<endl; 
  cin>>n;
  vector<int> vct;
  cout<<"Enter the elements of the array"<<endl;
  int i;
  while(n--) {
     cin>>i;
     vct.push_back(i);
  }
  cout<<"Enter the element count to revert the sign"<<endl;
  cin>>k;

  int sum = MaximizeArraySum(vct, k);
  cout<<"Miximized sum is: "<<sum<<endl;

  return 0;
}
