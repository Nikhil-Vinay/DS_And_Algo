/** There are k stacks of plates, each stack contain n plates. each plate has a value associated with it.
 * you have to select exactly p plates from stack with below constraints:
 * 1. you can select plates from any stack and not mandatory to select plates from all stack.
 * 2. stack top starts with 0th index and if you select jth plate from any stack, you need to select all plates from 0 to j-1 from that stack. Plate xant be selected from middle.
 *
 * You have to maximize the value by selecting p plapes.
 */

/* Note: This looks like more than 2D DP but you see by creating prefix array and having handling properly, 
 * it is 2D DP only. Its good example to think about.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void CreatePrefixArray(vector<vector<int> >&vct, int k, int n)
{
   for(int i = 0; i < k; i++) {
      for(int j = 1; j < n; j++) {
          vct[i][j] = vct[i][j] + vct[i][j-1];
      }
   }
}

// stackIdx and selected varies only
// stackIdx..[0.. k-1]
// selected..[0..p-1]
// Each state has a for loop (0..n-1)
// TIme complexity = O(n*p*k)
// state complexity = O(k*p)

int GetMaxValue(vector<vector<int> >&vct, int stackIdx, int selected, int k, int n, int p, int** dp)
{
   if(selected == p) {
       return 0;
   }

   if(selected > p || stackIdx >= k) {   // invalid case
      return INT_MIN;
   }

   if(dp[stackIdx][selected] != INT_MIN) {
      return dp[stackIdx][selected];
   }

   int ans = INT_MIN;
   for(int i = 0; i < n; i++) {

      int val = max ((vct[stackIdx][i] + GetMaxValue(vct, stackIdx+1, selected+i+1, k, n, p, dp)),  // selected
                      GetMaxValue(vct, stackIdx+1, selected, k, n, p, dp)                           // rejected
                );
      ans = max(val, ans);
   }

   dp[stackIdx][selected] = ans;
   return ans;
}

int main()
{
   int k; // number of stacks
   int n; // number of elements in each stack
   int p; // total number of elements to select

   cout<<"Enter k, n, p: "<<endl;
   cin>>k>>n>>p;

   vector<vector<int> > stackVct;

   for(int i = 0; i < k; i++) {
      cout<<"Enter stack-"<<i+1<<" values: "<<endl;
      vector<int> tmp;
      for(int j = 0; j < n; j++) {
         int v;
         cin >> v;
         tmp.push_back(v);
      }
      stackVct.push_back(tmp);
   }

   CreatePrefixArray(stackVct, k, n);

   // create dp array
   int** dp = new int*[k];
   for(int i = 0; i < k; i++) {
      dp[i] = new int[p];
   }
   // initialize dp array
   for(int i = 0; i < k; i++) {
      for(int j = 0; j < p; j++) {
         dp[i][j] = INT_MIN;
      }
   }

   int maxVal = GetMaxValue(stackVct, 0, 0, k, n, p, dp);
   cout<<"Max selected value: "<<maxVal<<endl;
/*
   for(int i = 0; i < k; i++) {
      for(int j = 0; j < n; j++) { 
        cout<<stackVct[i][j]<<" ";
      }
      cout<<endl;
   }
*/
   return 0;
}

/*  Some examples:
 *  1. 2 4 5
 *     10 10 100 30
 *     80 50 10  50       Ans: 250
 *
 *  2. 3 2 3
 *     80 80
 *     15 50
 *     20 10              Ans: 180
 *
 */     
