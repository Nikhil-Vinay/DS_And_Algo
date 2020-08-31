/** There is a given string s and pattern string p, we need to find out if pattern string matches exactly with the given string.
 * pattern string can contain two special character '*' and '.'.
 * Rule:
 * '.' : It matches with only one character.
 * '*' : It matches with any number of character of its previous character.
 *       Ex: b*  will match 0 count of b ("") to n number of b.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool IsSameString(string s, string p)
{
   cout<<s<<" "<<p<<endl;
   int len1 = s.length();
   int len2 = p.length();
   int dp[100][100];
   // s is in row and p is in column, one extra row and column for "" string . It make sure to not access -1 index.

   dp[0][0] = 1;
   for(int i = 1; i <= len1; i++) {
      dp[i][0] = 0;
   }

   for(int j = 1; j <= len2; j++){
      if(p[j-1] == '*'){
         dp[0][j] = dp[0][j-2];
      }
   }

   for(int i = 1; i <= len1; i++){
      for(int j = 1; j <= len2; j++) {
         if((p[j-1] == s[i-1]) || (p[j-1] == '.')){
            dp[i][j] = dp[i-1][j-1];
         } else if (p[j-1] == '*'){
            dp[i][j] = dp[i][j-2];
            if((p[j-2] == s[i-1]) || (p[j-2] == '.')){
              dp[i][j] = dp[i][j] || dp[i-1][j];
            }
         } else {
           dp[i][j] = 0;
         }
      }
   }

   // print the table 
   for(int i = 0; i <= len1; i++) {
      for(int j = 0; j <= len2; j++) {
          cout<<dp[i][j]<<" ";
      }
      cout<<endl;
   }

   return dp[len1][len2];
}

int main()
{
   string s;
   string p;
   cout<<"Enter the string s"<<endl;
   cin>>s;
   cout<<"Enter the pattern string p"<<endl;
   cin>>p;
    
   if(IsSameString(s,p)){
      cout<<"True"<<endl;
   }else{
      cout<<"False"<<endl;
   }

   return 0;
}       
