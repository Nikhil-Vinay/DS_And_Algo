/* This problem was asked by Triplebyte.
 *
 * You are given n numbers as well as n probabilities that sum up to 1. Write a function to generate one of the numbers with its corresponding probability.
 *
 * For example, given the numbers [1, 2, 3, 4] and probabilities [0.1, 0.5, 0.2, 0.2], your function should return 1 10% of the time, 2 50% of the time, and 3 and 4 20% of the time.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int GetCountByProbability(float prob)
{
  return (int)(prob * 100.0);  // packing with respect to 100, we can pack in 10 also
}

int GetNumber(int* sample_array)
{
   return sample_array[rand() % 100];
}

int main()
{
   int num[4] = {1, 2, 3, 4};
   float prob[4] = {0.1, 0.5, 0.2, 0.2};

   int* sample_array = new int[100];
   int idx = 0;
   for(int i = 0; i<4; i++) {
      int count = GetCountByProbability(prob[i]);
      int tmp_idx = idx + count;
      while(idx < tmp_idx) {
         sample_array[idx++] = num[i];
      }
   }
 
   return 0;
}
