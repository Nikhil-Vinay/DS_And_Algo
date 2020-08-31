/************ Find minimum number of character insertion to make a string palindrome ****************/
/*
 * It is quite similar to find the number of character deletion to make a string palindrome */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int MinCharInsertToPalindrome(string str)
{
  if(str.length() == 1 || str.length() == 0) {
     return 0;
  }
  int n = str.length();
  // create 2-D dp table
  int** table = new int*[n];
  for(int i = 0; i < n; i++) {
     table[i] = new int[n];
  }

  // Single character is palindrome itself, so number of insertion will be zero, so all diagonals element will
  // remain 0
  //
  // We need to iterate for all diagonals to check in different length windows
  // if we check in window[i,j] = number of insertion in window [i+1, j-1], if (str[i] == str[j]) 
  //                            = min (number of insertion in window[i+1, j], number of insertion in window
  //                                   [i, j-1]) + 1; 
  //
  // number of diagonal is n, where diagonal for 1 char window is already filled by zero so rest diagonal count
  // is n-1.
  //
  // Note: We can write recursive solution, top-down approach on the basis of above conditions.

  for(int i = n-1; i >= 1; i--) {
     // find each cell x and y index
     for(int x = 0; x < i; x++) {
        int y = (n-i) + x;
        if(str[x] == str[y]){
           table[x][y] = table[x+1][y-1]; 
        } else {
           table[x][y] = min(table[x][y-1], table[x+1][y]) + 1;
        }
     }
  }

  return table[0][n-1];
}

int main()
{

  //string str("ab");
  //string str("abcd");
  string str("abcda");
  cout<<MinCharInsertToPalindrome(str)<<endl;
  return 0;
}
