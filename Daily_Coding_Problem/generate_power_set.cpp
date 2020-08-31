/*********** Generate power set of a set (Generate all combinations) *********************/
/*********** Asked By Google **********/

/* The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power
 * set.
 * For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.
 *
 * You may also use a list or array to represent a set.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void Permutations(string &str, string printstr, int index, int length)
{
  if(index == length) {
    cout<< "{";
    cout<<printstr;
    cout<< "}"<<endl;
    return;
  }
 
  char char_at_index = str[index]; 
  Permutations(str, printstr, index+1, length);               // exclude
  Permutations(str, printstr+char_at_index, index+1, length); // include 
}

int main()
{
  string str("123");
  string printstr("");
  Permutations(str, printstr, 0, str.length());
  return 0;
}
