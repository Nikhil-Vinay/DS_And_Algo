/********** Find Min Distance Between Two Cities *****************/

/*** There are n cities and distance between them are given in two dimensional arrays. Find minimum distance
 * between two cities X and Y
 *
 * Ex: there are four cities A(0), B(1), C(2). D(3)
 *     
 *                0   5   6  12
 * dist[4][4] =   0   0   2  7
 *                0   0   0  5
 *                0   0   0  0
 *
 * Here min distance between A to D = 11
 *
 * Note: This problem can be solved by bfs using graph concept also.
 *
 * Time complexity of below solution if O(n2) and space complexity is O(n). n is number of city.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<typename T, size_t M, size_t N>
int MinDistance(T (&dist)[M][N])  // capture the size at compile time
{
   // here we know M = N
   int* table = new int[M];
   // table[i] denotes min distance between "city 0" to "city i"
   // we'll fill tables from 0 to n-1 linearly. 

   table[1] = dist[0][1];   // distance between "city 0" to "city 1"
   
   for(int i = 2; i < M; i++) {
     int min = INT_MAX;
     for(int j = 0; j < i; j++) {
        if((table[j] + dist[j][i]) < min) {
           min = table[j] + dist[j][i];
        }
     }
     table[i] = min;
   }

   return table[M-1];
}

int main()
{
  int distance[4][4] = { { 0, 5, 6, 12 },
                         { 0, 0, 2, 7  },
                         { 0, 0, 0, 5  },
                         { 0, 0, 0, 0  } };

  cout<<"Minimum distance between city A to D is : "<<MinDistance(distance)<<endl;
  return 0;
}
