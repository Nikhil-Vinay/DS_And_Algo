/********** This is the fastest way to solve n queen problem ********/

/* SOme concept:
 * n & (-n)  // extracts only last set bit, ex: n = 6 (0110), n & (-n) = 0010
 */

#include<iostream>
#include<stdlib.h>
#include<vector>


using namespace std;

int n, DONE;
int ways = 0;

void Solve(int rowmask, int ldmask, int rdmask)   // rowmask, left diagonal mask, right diagonal mask
{
  if(rowmask == DONE)
  {
    ways++;
    return;
  }

  int safe = DONE & (~(rowmask | ldmask | rdmask));
 
  while(safe)
  {
    int p = safe & (-safe);
    Solve(rowmask|p, (ldmask|p) << 1, (rdmask|p) >> 1);
    safe = safe & (safe-1);
  }
  
  return;
}

int main()
{

  cout<<"Enter the number of rows/col: "<<endl;
  cin >> n;

  DONE = (1 << n)-1;

  Solve(0, 0, 0);
  cout<< "Number of ways in n queen is: "<<ways<<endl;
     
  return 0;
} 
