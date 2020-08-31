/* Problem Statement:
   There are N sticks given of lengths - l1, l2, l3...lN (lengths could be same of more than one sticks)
   We need to make a signbord and it needs two euilength parallel stand for the same.
   What would be the maximim height of the signbord, if we make the two equilength stands of the signboard
   by joining these sticks.
   Note: it's not mandatory to use all the sticks.
*/

/* My code explanation:
   1. Find the maximum possible signboard length = (sum of all stick lengths) / 2;
2. Iterate for all lengths starting from (sum_of_all_stick_lengths)/2 to zero.
3. For each sum create a 2d dp array of boolean data - dp[num_of_sticks + 1][length+1]
   then populate the dp array by inclusion/exclusion method of sticks to form the corresponding length_sum.
   Used API: PopulateSumSubsetCount
4. Then, recursively find out for the given sum is possible or not with the help of populated 2d dp table.
   For every possibility, we increase the subset_count.
   Used API: UtilitySumSubsetCount
5. If we see subset_count is greater than 1, then right away result is found. 

Time complexity: O(n * sum/2 * sum/2) 

problem: It finds out the overlapping subsets of a perticular sum so it throws wrong answer.
         Ex: total number of sticks - 4
             Lengths of sticks - 3 3 3 4
             Output of program - 6 (it considers (3+3) and (3+3))
             Right output should be - 3
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
#define DEBUG 0 
int N;  // global variable for number of sticks
int subset_count = 0;
bool **dp;

void UtilitySumSubsetCount(vector<int> &vct, int i, int sum, vector<int>& p)
{
    // if sum is not zero at the end and vct[0] is equal to dp[0][sum]
    // then increase the subset count
    if (i == 0 && sum != 0 && (dp[0][sum] == vct[0]))
    {
        subset_count++;
        return;
    }
 
    // increase the subset count if sum is zero
    if (i == 0 && sum == 0)
    {
        subset_count++;
        return;
    }
 
    // check for the sum by excluding this element
    if (dp[i-1][sum])
    {
        // new vector for different subset
        vector<int> b = p;
        UtilitySumSubsetCount(vct, i-1, sum, b);
    }

    // check for the sum by including this element
    if (sum >= vct[i] && dp[i-1][sum-vct[i]])
    {
        p.push_back(vct[i]);
        UtilitySumSubsetCount(vct, i-1, sum-vct[i], p);
    }
}

void PopulateSumSubsetCount(vector<int> &vct, int n, int sum)
{
  if(n == 0 || sum < 0)
     return;

  dp = new bool*[n+1];
  for(int i = 0; i <= n; i++)
     dp[i] = new bool[sum+1];

  for(int i = 0; i <= n; i++)
      dp[i][0] = true;
  for(int j = 1; j <= sum; j++)
      dp[0][j] = false;

  for(int i = 1; i <=n; i++)
  {
     for(int j = 1; j <= sum; j++)
     {
        if(vct[i] > j)
        {
          dp[i][j] = dp[i-1][j];
        }
        else
        {
          dp[i][j] = dp[i-1][j] || dp[i-1][j-vct[i]];
        }
     }
  }

  if(dp[n][sum] == false)
     return;

  // Get the total number of subsets of sum
  vector<int> p;
  UtilitySumSubsetCount(vct, n, sum, p);

  return;
  
}

int main()
{
  cout<< "Enter the number of sticks: "<<endl;
  cin >> N;
  vector<int> sticks;
  sticks.resize(N);
  for(int i = 0; i < N; i++)
  {
     cin >> sticks[i];
  }
#if DEBUG
  for(int i = 0; i < N; i++)
  {
    cout<<sticks[i]<<endl;
  }
#endif

  int sum = std::accumulate(sticks.begin(), sticks.end(), 0);
  int maxlength = 0;
  for(int i = sum/2; i >= 1; i--)
  {
     PopulateSumSubsetCount(sticks, N, i);
     if(subset_count > 0)
     {
        maxlength = i;
        break;
     }
  }

  if(maxlength > 0)
    cout<<" Maximum Length Of The Signboard stand is - "<<maxlength<<endl;
  else
    cout<<"Making signboard stand is not possible"<<endl;

  return 0;
}
