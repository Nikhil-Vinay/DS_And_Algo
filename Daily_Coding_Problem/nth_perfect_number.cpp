/* Print nth perfect number */
/* A number is called perfect if sum of its all digits is 10 */

/* If we take a closer look, we can notice that all multiples of 9 are present in arithmetic progression 19, 28, 37, 46, 55, 64, 73, 82, 91, 100, 109, ….
 * However, there are numbers in above series whose sum of digits is not 10, for example, 100. So instead of checking one by one, we start with 19 and increment by 9 *
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void PrintNthPerfectNumber(int n)
{
  int start = 19;
  int count = 1;

  while(count < n) {
     start += 9;
     // check if perfect number
     int sum = 0;
     int cur = start;
     while (cur > 0) {
       sum += cur%10;
       cur = cur/10;
     }

     if(sum == 10) {
       count++;
     }
  }
  cout<<"Perfect Number at index : "<<n<<" is: "<<start<<endl;
}

int main()
{
  int n;
  cout<<"Provide index of perfect number:"<<endl;
  cin>>n;
  PrintNthPerfectNumber(n);
  return 0;
}
