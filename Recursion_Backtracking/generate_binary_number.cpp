#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void PrintBinaryUtil(string str, int n)
{
  if(0 == n) {
    cout<<str<<endl;
    return;
  }

  PrintBinaryUtil(str + "0", n-1);
  PrintBinaryUtil(str + "1", n-1);
}

void PrintBinary(int n)
{
  string str = "";
  PrintBinaryUtil(str, n);
}

int main()
{
   int n;
   cout<<"Provide digit count of binary numbers:"<<endl;
   cin>>n;
   cout<<"Binary Numbers Are: "<<endl;
   PrintBinary(n);
   return 0;
}
