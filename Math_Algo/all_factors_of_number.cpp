/* Print all factors of a number *
 * We know if a X b = n then if a exists left side of sqrt(n) then b exists right side of sqrt(n).
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void GetFactors(int n, vector<int> &factors)
{
   for(int i = 1; i*i <= n; i++) {
      if(n%i == 0) {
         factors.push_back(i);
         if(i*i != n) {
           factors.push_back(n/i);
         }
      }
   }
}

int main()
{
   int n;
   cout<<"Enter the number: "<<endl;
   cin>>n;
   vector<int> factors;
   GetFactors(n, factors);

   cout<<"factors of "<<n<<" are: "<<endl;
   for(int i = 0; i < factors.size(); i++) {
      cout<<factors[i]<<" ";
   }
   cout<<endl;
   return 0;
}
