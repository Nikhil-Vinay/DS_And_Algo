/*********** Find Nth Catalan Number ****************/
/* Application of catalan number:
 *  https://www.geeksforgeeks.org/applications-of-catalan-numbers/
 */

/* Some known problems on catalan number:
 * 1. Find number of BSTs made by n nodes.
 * 2. Number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, 
 *    possible expressions are ((())), ()(()), ()()(), (())(), (()()).
 * 3. Number of ways to insert n pairs of parentheses in a word of n+1 letters, e.g., for n=2 there are 2 ways: 
 *    ((ab)c) or (a(bc)). For n=3 there are 5 ways, ((ab)(cd)), (((ab)c)d), ((a(bc))d), (a((bc)d)), (a(b(cd))).
 * 4. Number of Dyck words of length 2n. A Dyck word is a string consisting of n X’s and n Y’s such that no 
 *    initial segment of the string has more Y’s than X’s.  For example, the following are the Dyck words of 
 *    length 6: XXXYYY     XYXXYY     XYXYXY     XXYYXY     XXYXYY.
 * 5. Number of ways to form a “mountain ranges” with n upstrokes and n down-strokes that all stay above the 
 *    original line.The mountain range interpretation is that the mountains will never go below the horizon.
 */

/* There are many more examples.
 * We can understand the formulae by problem: find number os BSTs made by n keys.
 * if n = 0; // no of BST is 1
 * if n = 1; // no of BST is 1
 *
 * Now for all i (1 to n), no of BST = (no of BST left side of i) x (no of BST right side of i)
 * Sum up the solution for all i to find the answer.
 */

/* General formula to find out nth catalan number: (2nCn)/(n+1)   // C stands for combination */
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int catalan(int n, unsigned long int* dp)
{
   if (n == 0 || n == 1 ) {
       return 1;
   }

   if(dp[n]) {
      return dp[n];
   }

   int sum = 0;
   int left_sol = 0;
   int right_sol = 0;
   for(int i = 1; i <= n; i++) {
      left_sol = dp[i-1] ? dp[i-1] : catalan(i-1, dp); 
      right_sol = dp[n-i] ? dp[n-i] : catalan(n-i, dp);
      sum += (left_sol * right_sol);
   }

   dp[n] = sum; 
   return sum; 
}

int main()
{
   int n;
   unsigned long int* dp = NULL;
   cout<<"Enter the number to calculate catalan:"<<endl;
   cin >> n;
   dp = new unsigned long int[n+1];
   for(int i = 0; i < n; i++) {
      dp[i] = 0;
   }
   cout<<"Output is: "<<catalan(n, dp)<<endl;
   delete[] dp;
   return 0;
}
