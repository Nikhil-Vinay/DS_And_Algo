/************ TSP (Travelling Salesman Problem) *******************************/

/* There are n cities all are connected in a perticular fashion. All could be connected with each other or
 * may not. A salesman is living in city A, we need to find out minimum cost to make a hamiltonian visit of
 * all cities by the salesman. 
 * All cities connection has some weight assigned for trvelling. 
 *
 * Hamiltonian visit means: start from A and come back to A by any path but all cities should be covered and 
 * no cities should be covered twice. *
 */

/* This problem is classical example of DFS, bit-masking and DP as well */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define CITY_COUNT 5

int TSP(int cost[][CITY_COUNT], int city, int mask)
{
   //if (mask == (pow(2, CITY_COUNT)-1)) {  // mask == (1<<CITY_COUNT - 1)
   //cost is constatnt so here if we'll apply DP then dp state will be - dp[2^CITY_COUNT][CITY_COUNT]
   // Each recursion call will have internally a for loop - (0...CITY_COUNT)
   // so total time complexity = O(2^CITY_COUNTxCITY_COUNTxCITY_COUNT) = O(2^N.N^2)

   if (mask == (1<<CITY_COUNT)-1) {  // mask == (1<<CITY_COUNT - 1)
      return cost[city][0]; 
   }

   int mincost = INT_MAX;
   for(int i = 0; i < CITY_COUNT; i++) {
      // check if city is not travelled by mask
      if((mask & (1 << i)) == 0) {
         int tempcost = cost[city][i] + TSP(cost, i, mask | (1 << i));
         mincost = min(mincost, tempcost);
      }
   }
   return mincost;
}

int main()
{
   /* There are five cities - A(0), B(1), C(2), D(3), E(4)
      travel cost details:
      A(0) - B(1) = 10 
      A(0) - C(2) = 5
      A(0) - D(3) = 6
      A(0) - E(4) = 20
      B(1) - C(2) = 15
      B(1) - D(3) =  5
      B(1) - E(4) = 8
      C(2) - D(3) = 5
      C(2) - E(4) = 10 
      D(3) - D(4) = 6*/

  int cost[CITY_COUNT][CITY_COUNT] = { {0, 10, 5, 6, 20},
                                       {10, 0, 15,5, 8 },
                                       {5, 15, 0, 5, 10},
                                       {6, 5,  5, 0, 6 },
                                       {20,8, 10, 6, 0 }};

  cout<<"Min travelling Cost is : "<<TSP(cost, 0, 1)<<endl;

  return 0;
}

