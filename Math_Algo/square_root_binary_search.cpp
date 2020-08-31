/**** Calculate square root by binary search till n decimal place *********/
/**** Fastest algorithm to calculate square root of a number *******/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int SqrtDecimalPartUtil(int n)
{
   int ans = 0;
   int start = 0, end = n, mid = 0;
   // time complexity = O(logn)
   while(start < end) {
      mid = start + (end - start)/2;
      if(mid*mid == n) {
         ans = mid;
         break;
      } else if (mid*mid < n) {  // ans lies in right side, current mid could be the ans
         ans = mid;              // because (mid+1)*(mid+1) could exceed the n
         start = mid+1;
      } else {  // ans lies in left side
         end = mid;
      }
   }
   return ans;
}

float SqrtWithFractionalPartUtil(int n, int d, int m)
{
   float x = 0.1;
   float result = d + 0.0;

   // time complexity = O(m*9) ~ O(m)
   while(m >= 0) {
     int i;
     for(i = 1; i <= 9; i++) {
        float temp = result + (x * i);
        if(temp * temp > (float)n) {
           break;
        }
     }
     
     result += (x * (i-1));
     x = (x/10);  // 0.1 -> 0.01 -> 0.001 -> ... 
     m--;
   }
   return result;
}

float GetSqrt(int n, int m)
{
   // Get decimal part of square root of n
   // Time complexity = O(logn)
   int d = SqrtDecimalPartUtil(n);
   if (d*d == n) {
      return float(d);
   } else {
      // Time complexity = O(m)
      return SqrtWithFractionalPartUtil(n, d, m);
   }
   // Total time complexity = O(logn) + O(m)
}

int main()
{
  int n, m;
  cout<<"Enter the number: "<<endl;
  cin >> n;
  cout<<"Enter the decimal place precision: "<<endl;
  cin>>m;
  float sqrt = GetSqrt(n, m);
  cout<<"Square root is: "<<sqrt<<endl;
  return 0;
}
