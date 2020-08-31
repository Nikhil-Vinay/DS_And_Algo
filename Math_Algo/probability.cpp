// Find the number of employees in a room so probability of two person having same birthday is 0.5
// Note: number of employees to make probability 1 of two person having same birthday is 366 (if 365 days in a yera(non leap year)
// If there are two persons are in a room then what is the probability of having same birthdays
// it will be 1 /365 (we have to choose 1 from 365)
// so, what is probability of having all two people different birthday  - (1- 1/365) = 364/365
// Note: Other ways to come to soln is - first person can choose birthday in 365 ways - so probability - 365/365
// second person can choose has 364 option to make different birthday so, probability is 364/365
// probability of having two people in room and having different birthdays is - 365/365 * 364/365 = 364/365

// so probability of having n people different birthday in a room is - P = 365/365 * 364/365 * 363/365 -----n times
// so probability of n people not having distinct birthdays is - (1-P)

// 1 - P >= 0.5
//   P <= 0.5

#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
  float num = 365;
  float denom = 365;
  float P = 1;

  int n  = 0;
  while( P > 0.5)
  {
    P = P*(num/denom);
    num--;
    n++;
  }

  cout<<"Number of people in a room to have different birthday probability as 0.5 is --"<<n<<endl; 

  return 0;
}
