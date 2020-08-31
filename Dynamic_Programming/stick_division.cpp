/*
 * You have a stick of length x and you want to divide it into n sticks, with given lengths, whose total length is x.
 *
 * On each turn you can take any stick and divide it into two sticks. The cost of such an operation is the length of the original stick.
 *
 * What is the minimum cost needed to create the sticks?
 *
 * Example
 *
 * Input:
 * 8 3
 * 2 3 3
 *
 * Output:
 * 13
 *
 * Explanation: You first divide the stick of length 8 into sticks of length 3 and 5 (cost 8). After this, you divide the stick of length 5 into sticks of length 2 and 3 (cost 5). The total cost is 8+5=13.
 */
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int MinCostUtil(int* prefix, int start, int end, int** dp)
{
   if(start == end){
      return 0;
   }

   if(end-start == 1){
      return (prefix[end]-(start==0?0:prefix[start-1]));
   }

   if(dp[start][end]){
     return dp[start][end];
   }

   int cost = INT_MAX;
   for(int i = start; i < end; i++) {
      int tmpcost = (prefix[i]-(start==0?0:prefix[start-1])) + (prefix[end] - prefix[i]);
      tmpcost += MinCostUtil(prefix, start, i, dp);
      tmpcost += MinCostUtil(prefix, i+1, end, dp);
 
      cost = min(cost, tmpcost);
   }

   dp[start][end] = cost;
   return cost;
}

int FindMinCost(vector<int> &vct)
{
   int count = vct.size();
   int* prefix = new int[count];
   // store prefix
   prefix[0] = vct[0];
   for(int i = 1; i < count; i++) {
      prefix[i] = prefix[i-1]+vct[i];
   }

   int** dp = new int*[count];
   for(int i = 0; i < count; i++){  
       dp[i] = new int[count]();
   }

   return MinCostUtil(prefix, 0, count-1, dp); 
}

int main()
{
   int len, count;
   cin>>len>>count;

   vector<int> vct;

   for(int i = 0; i < count; i++) {
      int tmp;
      cin>>tmp;
      vct.push_back(tmp);
   }

   cout<<FindMinCost(vct)<<endl;
   return 0;
}
