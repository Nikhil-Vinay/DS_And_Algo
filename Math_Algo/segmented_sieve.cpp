/* Print all the prime numbers between L and R.
 * 2 < l < U <= val  ( val > 10^8)
 * U-L <= 1000000
 *
 * we can create max of size of 10^8, not greater than this.
 * But we can make sieve of U-L size.
 *
 * Explained at youtube channel of coding ninja.
 */

#include<iostream>
#include<bits/stdc++.h>
#define MAX 1000001

using namespace std;

vector<int>* sieve() 
{
   bool isPrime[MAX];
   for(int i = 0; i < MAX; i++) {
       isPrime[i] = true;
   }

   for(int i = 2; i*i < MAX; i++) {
       if(isPrime[i]) {
          for(int j = i*i; j < MAX; j += i) {
             isPrime[j] = false;
          }
       }
   }

   vector<int>* primes = new vector<int>();
   primes->push_back(2);
   for(int i = 3; i< MAX; i+= 2) {   // prime can be only odd number
       if(isPrime[i]) {
          primes->push_back(i);
       }
   }

   return primes;
}

void printPrimes(long long l, long long r, vector<int>* primes)
{
   // apply here segmented sieve logic
   bool isPrime[l-r+1];
   for(int i = 0; i <= r-l; i++) {
      isPrime[i] = true;
   }

   for(int i = 0; primes->at(i)*(long long)primes->at(i) <= r; i++){
      int curPrime = primes->at(i); 
      // just smaller or equal value to l
      long long base = (l/curPrime)*curPrime;
      if(base < l) {
         base += curPrime;
      }

      // mark all multiples within l to r as false
      for(long long j = base; j <= r; j+=curPrime) {
         isPrime[j-l] = false;
      }

      // There may be a case where base is itself a prime number
      if(base == curPrime) {
        isPrime[base-l] = true;
      }
   }

   for(int i = 0; i <= r-l; i++) {
      if(isPrime[i] == true) {
         cout<<i+l<<endl;
      }
   }
}

int main()
{
   vector<int>* primes = sieve();
   int t;
   cin >> t;
   while(t--){
     long long l, r;
     cin>>l>>r;
     printPrimes(l, r, primes);
   }

   return 0;
}
