/* Given a string, determine whether any permutation of it is a palindrome.
 *
 * For example, carrace should return true, since it can be rearranged to form racecar, which is a palindrome. daily should return false, since there's no rearrangement that can form a palindrome.
 *
 * Note: Number of permutation of string of length n = n! (factorial n)
 */

/* Below solution uses set. If we will use hash_set then search complexity will go down from O(logN) to O(1).
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool IsPalindrome(string str)
{
   bool ret = true;
   int start = 0, end = str.length()-1;
   while (start < end) {
     if(str[start++] == str[end--]) {
        continue;
     }
     ret = false;
     break;
   }
   return ret;
}

void PrintUniquePermutation(string str, int index, set<string> &myset)
{
  int len = str.length();
  if(index >= len) {
     if(myset.find(str) == myset.end()) {
        if(IsPalindrome(str)) {
           cout<<str<<" is palindrome"<<endl;
        } else {
          cout<<str<<endl;
        }
        myset.insert(str);
     }
     return; 
  }

  for(int i = index; i < len; i++) {
     // swap between i and index
     char temp = str[index];
     str[index] = str[i];
     str[i] = temp;
     PrintUniquePermutation(str, index+1, myset);
     // back track (swap back)
     temp = str[index];
     str[index] = str[i];
     str[i] = temp;
  }   
}

int main()
{
   string str;
   set<string> myset;
   cout<<"Enter the string: "<<endl;
   cin >> str;
   cout<<"Permutations are: "<<endl;
   PrintUniquePermutation(str, 0, myset);
   return 0;
}
