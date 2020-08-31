/* Prob: There are N elements in an array, except one element each elements occurs 3 times.
 *  Fnd out the element which ocurs only once */

/* Note: Below mwthod can be applied on any variant of this probles, example, except onde element each element 
   occurs n times. We need to take modulus by n in this case. */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void PrintUnique(vector<int> &vct, size_t size)
{
  vector<int> tmpvct(32, 0);
  for(size_t i = 0; i < 32; i++)
  {
    for(size_t j= 0; j < size; j++)
    {
       if(vct[j] & (1 << i))
       {
         tmpvct[i]++;
       }
    }
  }

  int element = 0;
  // Take modulus and construct unique element
  for(size_t i = 0; i < 32; i++)
  {
     tmpvct[i] = (tmpvct[i]% 3);
    
     if(tmpvct[i]) 
        element |= (1 << i);
  }

  cout<<"Unique element is--"<<element<<endl;
}

int main()
{
  int num;
  cout<<"Please enter the number of nums:"<<endl;
  cin>>num;
  vector<int> vct(num, 0);
  for(int i = 0; i < num; i++)
   cin>>vct[i];

  PrintUnique(vct, vct.size());
  return 0;
}
