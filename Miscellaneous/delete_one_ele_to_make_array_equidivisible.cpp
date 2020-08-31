// Check if an array can be devided into two equal parts after removing any one element
#include<iostream>

using namespace std;

template <typename T, std::size_t sz>
std::size_t size(T (&) [sz])
{
  return sz;
}

int GetArrSum(int *arr, int len)
{
  int val = 0;
  for(int i = 0; i < len; i++)
    val += arr[i];

  return val;
}

void PrintSubArray(int *arr, int startIndex, int endIndex)
{
  if(startIndex > endIndex)
  {
    cout<<"{}"<<endl;
    return;
  }
  cout<<"{";
  for(int i = startIndex; i <= endIndex; i++)
  {
    cout<<" "<<arr[i]<<" ";
  }
  cout<<"}";
}

bool IsPossible(int *arr, int index, int totalSum, int currentVal)
{
  if(index < 0)
    return false;

  if((totalSum - arr[index] - currentVal) == currentVal)
  {
     cout<<"Yes array can be divided and the sets are - "<<endl;
     PrintSubArray(arr, 0, index-1);
     cout<<" And ";
     PrintSubArray(arr, index+1, 4);
     return true;
  }

  return IsPossible(arr, index-1, totalSum, currentVal+arr[index]);
}

int main()
{
  int arr[5] = { 6, -2,  -3, 2, 3};
  int toalsum = GetArrSum(arr, size(arr));
  bool isPossible = IsPossible(arr, 4, toalsum, 0);  
  if(isPossible)
    cout<< "Yes it is possible"<<endl;
  else
    cout<< "Yes it is not possible"<<endl;
  return 0;
}
