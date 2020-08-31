/*** String C is said to be interleaving of string A and B if it contains all the characters of A and B and
 * relative order of characters of both the strings are preserved in C.
 *
 * Exapmle: A = "xyz",  B = "abcd"
 *          C = "xabyczd"  (It is interleaving of strings A and B)
 *
 * Note: As we look into above example then it looks easy as we'll have three pointers at string A, string B and
 * string C then we try to match .. if char at String C pointer matches with  char at string A pointer then
 * we increment string C pointer and string A pointer. Similarly, if char at String C pointer matches with char
 * at string B pointer then we increment string C pointer and string B pointer and so on...easy right?
 *
 *Now think if char at string C pointer matches with both (char at string A pointer and char at string B pointer)
  then which could increase, and suppose this situation happens multiple time during check then it needs to 
  check all the ways and it will run exponentially and there will too many repitition as well.

   A recursive solution is below but that is exponential in time complexity. Bottom up iterative solution is best
   for DP solution.
 *
 */         

#include<iostream>
#include<bits/stdc++.h>
#define DEBUG 0
using namespace std;

// recursive solution
// for 2-d dp, we need to pass i and j (i is current index of str1 and j is current index of str2)
// str3 index will be (i+j)
bool StringInterleaving(const char* str1, const char* str2, const char*str3)
{
   if((str1 == NULL || *str1 == '\0') && (str2 == NULL || *str2 == '\0')) {
      if(str3 == NULL || *str3 == '\0') {
         return true;
      } else {
         return false;
      }
   }

   if(str1 == NULL || *str1 == '\0') {
      return (strcmp(str2, str3) == 0);
   }

   if(str2 == NULL || *str2 == '\0') {
      return (strcmp(str1, str3) == 0);
   } 

   bool ans1 = false, ans2 = false;
   if(*str1 == *str3) {
     ans1 = StringInterleaving(str1+1, str2, str3+1);
   }

   if(*str2 == *str3) {
     ans2 = StringInterleaving(str1, str2+1, str3+1);
   }

   return (ans1 || ans2);
     
}

/* Note: In the above recursive solution, it seems all thrree strings are changing then how to apply for top-down
 * aipproach. For applying top down approach here, we need to change the func signature as below:
   bool StringInterleaving(const char* str1, const char* str2, const char*str3, int str1_idx, int str2_idx,
                           int** table)
 * We know str1, str2 and str3 are constant so we'll change the str1 start index (str1_idx) and str2 start index
 * (str2_idx) in each call. 
    str3 start index will be calculated as - (str1_idx + str2_idx - 1);
    Since two variables - str1_idx and str2_idx are changing so, we have 2-D dp table (table) in each call. */

// iterative dp solution 
int StringInterleavingDP(const char* str1, const char* str2, const char* str3)
{
  if((str1 == NULL || *str1 == '\0') && (str2 == NULL || *str2 == '\0')) {
      if(str3 == NULL || *str3 == '\0') {
         return 1;
      } else {
         return 0;
      }   
   }   

   if(str1 == NULL || *str1 == '\0') {
      return (strcmp(str2, str3) == 0); 
   }   

   if(str2 == NULL || *str2 == '\0') {
      return (strcmp(str1, str3) == 0);
   }

   // create dp table
   // will take one extra row and column for empty strings which will make our base conditions.
   int n = strlen(str1);
   int m = strlen(str2);

   int** table = new int*[n+1];
   for(int i = 0; i <= n; i++) {
      table[i] = new int[m+1];
   }

    // Very Important: It is clear that if we are at i-th row and j-th column then we are considering string1
    // till ith character, string2 till jth character and string3 till (i+j)th character.
    // For filling table[i][j], we check i-th character of string1, j-th character of string2 and (i+j)th char of
    // string 3.
    // i-th character of string1 = string1[i-1]
    // j-th cgaracter of string2 = sttring2[j-1]
    // (i+j)th chracter os string3 = string3(i+j-1)
    
    // fill the table for base conditions
    // It means that zero character of string1 and zero character of strin2 interleave to from string C of zero
    // character 
    table[0][0] = 1;

    // fill first row as per string2 with length m
    // Here since string1 has zero character so matching string2 with string3. Once a character mismatch happens
    // means 0 comes , going forward all cell will be zero because string equality fails over there only. As 
    // string1 has zero character then string2 needs to be equal of string3 to be interleaving strings.
    for(int i = 1; i <= m; i++) {
       if(str2[i-1] == str3[i-1]) {     // i+0-1 = i-1
         table[0][i] = table[0][i-1];
       } else {
         table[0][i] = 0;
       }
    }

    // fill first colum as per string1 with length n
    // Same as above explanation for row is applied here for column.
    for(int i = 1; i <= n; i++) {
       if(str1[i-1] == str3[i-1]) {      // i + 0 -1 = i-1
         table[i][0] = table[i-1][0];
       } else {
         table[i][0] = 0;
       }
    }

    // fill rest of the table
    for(int i = 1; i <= n; i++) {
       for(int j = 1; j <= m; j++) {
          if(str1[i-1] == str3[i+j-1] && str2[j-1] != str3[i+j-1]) {
            table[i][j] = table[i-1][j]; 
          } else if (str2[j-1] == str3[i+j-1] && str1[i-1] != str3[i+j-1]) {
            table[i][j] = table[i][j-1];
          } else if (str1[i-1] == str3[i+j-1] && str2[j-1] == str3[i+j-1]) {
            table[i][j] = table[i-1][j] || table[i][j-1];
          } else {
            table[i][j] = 0;
          }
       }
    }

    // print table
#if DEBUG
    for(int i = 0; i <= n; i++) {
       for( int j = 0; j <= m; j++) {
          cout<<table[i][j]<<"  ";
       }
       cout<<endl;
    } 
#endif
     
    return table[n][m];    
}

int main()
{
  char* str1 = "abcd";
  char* str2 = "xyz";
  char* str3 = "abxcyzd";

  //if(StringInterleaving(str1, str2, str3)) {
  if(StringInterleavingDP(str1, str2, str3)) {
     cout<<"strings are interleaving" <<endl;
  } else {
     cout<<"strings are not interleaving"<<endl;
  }
  return 0;
}
