// cycle sort is used when we have 1 to n elements shuffled and size of array is n. It takes O(n) time.
// Variance: It can be used if we have n contiguous numbers shuffled and we know the range of the element and array 
// size is n. This algo can be used in this case as well.
//
//Note: This sorting is all about placing the n at n-1th index as index starts from 0.

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

  cout<<"unsorted array is: "<<endl;
  for(int i = 0; i < n; i++) {
     cout<<vct[i]<<" ";
  }
  cout<<endl;

  // circular sort
  for(int i = 0; i < n; i++) {
     if(vct[i] == i+1){
        continue;
     } else {
        swap(vct[i], vct[vct[i]-1]);
     }
  }

  cout<<"sorted array is: "<<endl;
  for(int i = 0; i < n; i++) {
     cout<<vct[i]<<" ";
  }
  cout<<endl;

  return 0;
}
