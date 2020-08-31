/* Print all prime factors of a number */

/* Create prime number sieve then check for prime number factors */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void CreateSieve(int n, vector<bool> &sieve)
{
   for(int i = 0; i <= n; i++) {
     sieve[i] = true;
   }

   for(int i = 2; i*i <= n; i++) {
       if(sieve[i] == true) {
          for(int j = i*i; j <= n; j = j+i) {
              sieve[j] = false;
          }
       } 
   }
}

int main()
{
  int n;
  cout<<"Enter the number: "<<endl;
  cin >> n;
  vector<bool> sieve;
  sieve.resize(n+1);
  CreateSieve(n, sieve);

  cout<<"Prime factors of "<<n<<" are: "<<endl;
  for(int i = 1; i*i <= n; i++) {
     if (n%i == 0) {
         if(sieve[i] == true) {
           cout<<i<<" ";
         }
         if((i*i != n) && sieve[n/i] == true) {
           cout<<(n/i)<<" ";
         }
     }
  }
  cout<<endl;

  return 0;
}
