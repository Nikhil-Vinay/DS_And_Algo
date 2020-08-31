/************* Print nth perfect number *************************/

/*** A number is considered perfect if it's digits sum upto 10 **********/

/* Example: 1st perfect number - 19
 *          2nd perfect number - 28
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void PrintNPerfectNumber(int n)
{
   // 19, 28, 37, 46, 55, 64, 73, 82, 91
   // 109, 208...
   int numOfSameDigitCount = 9;
   int mult = 10;
   int i = 1;
   int j = 9;
   int x = 1;

   while(n > 0) {
      cout<<(i*mult+j)<<endl; 
      if (x == numOfSameDigitCount) {
         mult *= 10;
         i = 1;
         j = 9;
         x = 1; 
      } else {
        i++;
        j--;
        x++;        
      }
      n--;
   } 
}
 
int main()
{
  int n;
  cout<<"Provide index of the perfect number: "<<endl;
  cin >> n;
  PrintNPerfectNumber(n);
  return 0;
}          
