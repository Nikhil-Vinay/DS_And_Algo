// Find out if a number is perfect square without using any library as sqrt etc.
// Property of perfect square as: each prime divisior occurs twice.
// We know each number can be breaked into prime divisors
// Example: 100: 5x5x2x2 (perfect square)
//          50: 5x5x2    (not perfect square)
          
#include<iostream>

using namespace std;

int main()
{
   int n;
   cout<<"Enter the number: "<<endl;
   cin >> n;
   
   // checkout if number is perfect square
   // Method-1: Time complexity : O(n)
   int counter = 1;
   int number = n;
   while(number > 0) {
      number -= counter;
      counter += 2;
   }

   if(number == 0) {
     cout<<n<<" is perfect square"<<endl;
   } else {
     cout<<n<<" is not a perfect square"<<endl;
   }

   // Method-2: Using binary search , Time complexity: O(logn)
   int start = 1;
   int end = n;
   bool square = false;
   while(start < end) {
       int mid = start  + (end-start)/2;
       if(mid*mid == n) {
          square = true;
          break;
       } else if (mid*mid < n) {
          start = mid+1;
       } else {
         end = mid-1;
       }
    }

    if(square) {
      cout<<n<<" is perfect square"<<endl;
    } else {
      cout<<n<<" is not a perfect square"<<endl;
    }

    return 0;
}
