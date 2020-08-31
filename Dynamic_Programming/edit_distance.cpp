/************* EDIT DISTANCE PROB **********************/
/* The words COMPUTER and COMMUTER are very similar, and a update of just one letter, P->M, both will be same.
 * 
 * Edit distancce is defined as the minimum number of character opertion (update, delete, insert) required to
 * convert one string to another.
 */

#include<iostream>
#include<bits/stdc++.h>
#define DEBUG 0

using namespace std;

// recursive solution (exponential time)
/* We try to make str1 similar to str2, reverse way will also give the same result 
 * This solution is exponential in time complexity*/

int EditDistance(const char* str1, const char* str2)
{
   // think 2 mins for all base conditions
   if((str1 == NULL || *str1 == '\0') && (str2 == NULL || *str2 == '\0'))
      return 0;

   if(str2 == NULL || *str2 == '\0') {
     return strlen(str1);
   }

   if(str1 == NULL || *str1 == '\0') {
     return strlen(str2);
   }

   if(*str1 == *str2) {
     return EditDistance(str1+1, str2+1);;
   }

   int u = 0, i = 0, d = 0;  // u = update in str1, i = insert in str1, d = delete from str1
   u = EditDistance(str1+1, str2+1);  // updated so both string pointer moves to match with next chars
   i = EditDistance(str1, str2+1);    // inserted a character in begining of str1 so, only str2 will move
   d = EditDistance(str1+1, str2);    // deleted a char from begining of str1 so, str1 will move

   int ans = min(u, i);
   ans = min(ans, d);
   return ans + 1;
}

/* Note: In the above recursive solution, it seems both the string are changing then how to apply for top-down
 * approach. For applying top down approach here, we need to change the func signature as below:
 * int EditDistance(const char* str1, const char* str2, int str1_idx, int str2_idx, int** table)
 * We know str1 and str2 are constant so we'll change the str1 start index (str1_idx) and str2 start index
 * (str2_idx) in each call. Since two variables - str1_idx and str2_idx are changing so, we have 2-D dp table
 * (table) in each call. */



// iterative dp solution
int EditDistanceDP(const char* str1, const char* str2)
{
   if((str1 == NULL || *str1 == '\0') && (str2 == NULL || *str2 == '\0')) {
      return 0;
   }
 
   if(str2 == NULL || *str2 == '\0') {
     return strlen(str1);
   }   

   if(str1 == NULL || *str1 == '\0') {
     return strlen(str2);
   }

   // create dp table
   int n = strlen(str1);  // we try to make str1 as str2 so, consider length of str1 as row
   int m = strlen(str2);

   int **table = new int*[n+1];     // we are increasing on row and one colum for empty string (part of base case)
   for(int i = 0; i <= n; i++ ) {
      table[i] = new int[m+1];
   }

   // as per base case, if both string are empty then edit distance is 0 (It will fill table[0][0]). It means 
   // that zero character of str1 and zero character of str2 then edit distance is zero only.
   //
   // if one str1 is null then edit distance for str2 increases as character, ex: at first char of str2 -1 , at
   // second char of str2 - 2 (it will fill row 0)
   //
   // similarly if str2 is null then edit distance for str1 increases as character, ex: at first char of str1 -1 , 
   // at second char of str1 - 2 (it will fill column 0)

   table[0][0] = 0;
   for(int i = 1; i <= m; i++) {  // fill first row
      table[0][i] = i;
   }

   for(int i = 1; i <= n; i++) {  // fill first column
      table[i][0] = i;
   }   
 
   // think for 2 sec
   //
   // if str1[i] == str2[j] then table[i][j] = table[i-1][j-1]; // we are considering string1 till ith index and
   // string2 till jth index only, if characters are same at str1 at i and str2 at j then solution will be same as
   // 1 less index at str1 and 1 less index at str2
   //
   // if str1[i] != str2[j] then table[i][j] = min (table[i-1][j], table[i][j-1] and table[i-1][j-1]) + 1  
   // we are considering string 1 till ith index and string2 till jth index only so, if characters are not matching
   // for str1 at i and str2 at j then we are going to do one operation(update or delete or insert) for sure so
   // +1 is done. Now we would have reached at this index for both the strings by updation in string1, or deletion
   // in string 1 or insertion in string 1 so we'll look into all three solution and get minimum and finally will 
   // add 1.
   int ans = 0;
   for(int i = 1; i <= n; i++) {     // row (str1)
      for(int j = 1; j <= m; j++) {  // col (str2)
         if(str1[i-1] == str2[j-1]) {  // we need to check strings from 0th index so, i-1 and j-1
            table[i][j] = table[i-1][j-1];
         } else {
            ans = min(table[i-1][j], table[i][j-1]);
            ans = min(ans, table[i-1][j-1]);
            table[i][j] = ans+1;
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
  char *str1 = "COMPUTER";
  char *str2 = "COMMUTES";

  //cout<<"Min Edit Distance is: "<<EditDistance(str1, str2)<<endl;
  cout<<"Min Edit Distance is: "<<EditDistanceDP(str1, str2)<<endl;
  return 0;
}
