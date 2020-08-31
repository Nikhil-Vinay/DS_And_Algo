#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
   int x, y;
   cin>>x>>y;

   int extra = 1;
   int res = x;
   while( y > 1) {
      if (y%2 == 1){
          extra *= res;
      }
      res = res*res;
      y = y/2;
   }

   cout<<res*extra<<endl;
   return 0;
}

