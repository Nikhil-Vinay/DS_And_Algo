/* Given a string, we need to find the max distance between two same characters */
/* Example : "abcebfgbef", Ans = 5, number of characters between 'b' at index 1 and 7
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int MaxDistance(string &str)
{
  // since we have all small characters in string so using an array of size 26 for hashing.
  // we can use map for o(nlogn) time complexity for searching
  // we can use hash_map for o(1) time complexity for searching
  int hash[26];
  for(int i = 0; i < 26; i++) {
     hash[i] = -1;
  }

  int len = str.length();
  int max_dis = -1;
  for(int i = 0; i < len; i++) {
     int char_hash_val = str.at(i)-'a';
     if(hash[char_hash_val] == -1) {
       hash[char_hash_val] = i;
     } else {
       int temp = i - hash[char_hash_val]-1;
       if(temp > max_dis) {
          max_dis = temp;
       }
    }
  }

  return max_dis;
}

int main()
{
  string str;
  cout<<"Enter the string: "<<endl;
  getline(cin, str);

  cout<<"Max distance is: "<<MaxDistance(str)<<endl; 
  return 0;
}
