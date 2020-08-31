// There is given array of size n, which is supposed to have elements from 1 to n but by mistake some numbers are missing in the range and there is an duplicate number instead of each missing number, find out all the duplicate numbers and missing numbers.
//
// Note: It is based on cyclic sort

#include<iostream>
#include<vector>
using namespace std;

int main()
{
  vector<int> vct;
  int n; 
  cout<<"Enter the number of elements"<<endl;
  cin>>n;
  vct.resize(n);
  cout<<"Enter the elements: "<<endl;
  for(int i = 0; i < n; i++) {
    cin>>vct[i];
  }

  // circular sort
  for(int i = 0; i < n; i++) {
     if(vct[i] == i+1){
        continue;
     } else {
        if(vct[i] != vct[vct[i]-1]) {
           swap(vct[i], vct[vct[i]-1]);
        } else {
          cout<<"missing number is: "<<i+1<<" and repeated number is: "<<vct[i]<<endl;
        }
     }
  }

  return 0;
}
