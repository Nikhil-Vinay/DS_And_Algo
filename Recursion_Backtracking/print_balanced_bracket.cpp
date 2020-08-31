/***** Print all balanced brackets string for n open-close pair.
 * Example: n = 2
 *          ()()
 *          (())
 *
 *          n = 3
 *          ()()()
 *          ((()))
 *          (()())
 *          (())()
 *          ()(())
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void PrintBalancedBrackets(int n, int open_bracket_count, int closed_bracket_count, string str)
{
   if(closed_bracket_count == n) {
      cout<<str<<endl;
   }
 
   if(open_bracket_count > closed_bracket_count) {
      PrintBalancedBrackets(n, open_bracket_count, closed_bracket_count+1, str+")");
   }

   if(open_bracket_count < n) {
      PrintBalancedBrackets(n, open_bracket_count+1, closed_bracket_count, str+"(");
   }
}

int main()
{
   int n;
   cout<<"Please enter the number n : "<<endl;
   cin>>n;
   PrintBalancedBrackets(n, 0, 0, "");
   return 0;
}          
