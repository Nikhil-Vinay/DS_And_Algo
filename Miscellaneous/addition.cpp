#include<iostream>
using namespace std;
int Add(int x, int y)
{
   while (y != 0)
   {
       int carry =  x & y;
       cout<<"carry : " <<carry <<endl;
       x = x ^ y;
       y = carry<< 1;
       
       cout<< " Y : " <<y <<endl;
   }  
   return x;
}

int main()
{
  int x= 9 , y = 7;
  cout<<x << " + " << y << " = " << Add(x , y)<<endl;
  return 0;
}

