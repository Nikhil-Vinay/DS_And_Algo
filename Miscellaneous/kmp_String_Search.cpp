/*** KMP Algorithm for finding a pattern in a string ******************/
/*** Time complexity - O(n) *********/
/** Example:
 *  string: ABABABC
 *  pattern: ABABC
 *  lps[]  : 00120
 *
 *  o/p - pattern found at index 2.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define DEBUG 1

int KMPPatternSearch(string &str, string &pat)
{
  int idx = 0;
  // generate lps for pattern string
  int *lps = new int[pat.length()];
  for(int i = 0; i < pat.length(); i++) {
     lps[i] = 0;
  }

  int start = 0;
  int cur = 1;
  lps[0] = 0;  //always

  while(cur < pat.length()) {
     if(pat[cur] == pat[start]) {
        lps[cur] = lps[cur-1]+1;
        cur++;
        start++;
     } else {
       start = 0;
       lps[cur] = 0;
       cur++;  
     }
  }

#if DEBUG
  cout<<"lps array for pattern string "<<pat<<" is: "<<endl;
  for(int i = 0; i < pat.length(); i++) {
     cout<<lps[i]<<" ";
  }
  cout<<endl;
#endif

   // Start searching with help of lps array
   int str_index = 0;
   int pat_index = 0;

   while(str_index < str.length()) {
      if(str[str_index] == pat[pat_index]) {
         str_index ++;
         pat_index++;
      } else {
         pat_index = lps[pat_index-1];
      }
  
      if (pat_index == pat.length()) {  // pat is found
         return str_index - pat.length();  
      }
   }
   
   return -1;
}

int main()
{
   string str("ABABABC");
   string pat("ABABC");
   int a;

   if((a = KMPPatternSearch(str, pat)) != -1) {
     cout<<"Pattern found at index - "<<a<<endl;
   } else {
     cout<<"Pattern not found"<<endl;
   }

   return 0;
}
