/*************** Print all permutation of a word ***********************/
/** Very good example of backtracking and recursion, try yourself ******/
/* Total number of permutaion is n! , n is number of character. */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void PermutationUtil(string str, int start_index, int end_index)
{
  if (start_index == end_index) {
     cout << str << endl;
     return;
  }

  for(int i = start_index; i < end_index; i++) {
     swap(str[start_index], str[i]); // std::swap
     PermutationUtil(str, start_index+1, end_index);
     swap(str[start_index], str[i]); // backtracking
  }
  return;
}

void PrintPermutation(string str)
{
   PermutationUtil(str, 0, str.size());
}

int main()
{
  string str;
  cout << "Enter the string: "<<endl;
  cin>>str;
  PrintPermutation(str);
  return 0;
}
