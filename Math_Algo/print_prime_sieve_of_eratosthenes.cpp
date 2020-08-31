/****** Print all prime numbers less than or equal to of a given number ***********/
/****** This problem is solved by a popular and most effective method called "sieve of erastosthenes" ***/
/*
 * 1. we take an boolean array of n+1 and set all values as true. After traversal whichever values are not prime
 *    will set out to fasle.
 * 2. we start with i = 2 first prime number, till i*i <= n.
 * 3. if val at index i is prime number then we start another loop starting with j = i*i, till j<=n with incremental of j += i;
 
Concept:
Composie number: It is a positive number which is not prime.

Every composite number n has a prime factor(p) with below relation:
              p <= sqrt(n)

1. 2 is prime number so, 2*2 = 4, 4+2(6), 6+2(8), 8+2(10)...so on will be marked as non prime(false);
2. When we reach to next prime number 3 then we don't need to check for 3*2(it already covered with 2), we need
   to start directly with square of 3 (3*3).
   Similarly when we reach to prime number 7, we don't need to check for 7*2, 7*3...7*6. These are already taken
   care by multiple of 2,3,4,5,6..so we need to start directly with square of 7 as 7*7.

3. Asper above concept, we need to run the loop until (i*i) <= n only.

*/ 

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void PrintPrime(int n)
{
   // sieve of erastosthenes
   // create an array [n+1]
   bool prime[n+1];
   memset(prime, true, sizeof(prime));

   prime[0] = prime[1] = false;

   for(int i = 2; (i*i) <= n; i++) {
       if(prime[i] == true) {    // if prime[i] is not changed
         for(int j = i*i; j <= n; j = j+i){
            prime[j] = false;
         }
       }
   }

   // printing all primes
   cout<<"prime numbers less than equal to "<<n<<" are: "<<endl;
   for(int i = 2; i <= n; i++) {
      if(prime[i]) {
         cout<<i<<endl;
      }
   }
}


int main()
{
   int n;
   cout<<"Enter the number: "<<endl;
   cin>>n;
   PrintPrime(n);
   return 0;
}
