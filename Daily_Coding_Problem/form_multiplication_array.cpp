/********* Prob-2 (Hard): Form multiplication array *****************************/
/*  Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i .
 *
 *  Ex: Orig_Arr = [ 1, 2, 3, 4, 5]
 *      Out_Arr = [120, 60, 40, 30, 24]
 *
 * Restriction: Don't use devision operation to solve this problem.
 *
 *Note: variation of this prob, instead of multiplication, we can use addition, or  any kind of operation.
  Here trick is same opertaion will be performed on all elements except element at i. This concept is applied
  in all this kind of problem */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void PrintVector(vector<int> &vct)
{
  for(int i = 0; i < vct.size(); i++) {
    cout<<vct[i]<<" ";
  }
  cout<<endl;
}

vector<int> GetMultiplicationArray(vector<int> &vct)
{
  vector<int> tmpvct;

  // initialize temp vector with 1 at all index
  for(int i = 0; i < vct.size(); i++) {
    tmpvct.push_back(1);
  }

  // forward direction
  int val = 1;
  for(int i = 1; i < vct.size(); i++) {
    val = val * vct[i-1];
    tmpvct[i] = val;
  }

  // backward direction
  val = 1;
  for(int i = vct.size()-2; i >= 0; i--) {
    val = val * vct[i+1];
    tmpvct[i] *= val;
  } 

  return tmpvct;
}

int main()
{
  
  int arr[5] = { 1, 2, 3, 4, 5 };
  vector<int> vct(arr, arr+5);
  cout<<"Original vector is: "<<endl;
  PrintVector(vct);
  vector<int> multvct = GetMultiplicationArray(vct);
  cout<<"Multiplication vector is: "<<endl;
  PrintVector(multvct);

  return 0;
}
