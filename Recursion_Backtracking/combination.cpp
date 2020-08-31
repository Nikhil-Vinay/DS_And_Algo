/********************** Print all combinations of a word ****************/
/* Total number of combination of a word is pow(2, n). n is number of character in the word. */
/* Example string is ABC, total number of character is 3 so, total number of combination is pow(2, 3)= 8
 * "", C, B, BC, A, AC, AB, ABC
 * It can be easily observed as permuation is always based on binary pattern of n digits as below:
 * ""(000), C(001), B(010), BC(011), A(100), AC(101), AB(110), ABC(111)
 */
// Time complexity of below both methods are - O(number_of_combination)

/** Method-1 , Printing by binary pattern **/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#if 0

void PrintString(string str, string str_pattern)
{
  if(str.size() != str_pattern.size()) {
    cout<<"string size and pattern size are not equal, so asserting"<<endl;
    assert(false);
  }

  for(int i = 0; i < str.size(); i++) {
    if(str_pattern.at(i) - '0') {
      cout << str.at(i);
    }
  }
  cout<<endl;
}

void PrintCombinationUtil(string str, string str_pattern)
{
   string tmp_str_pattern("");
   if(str_pattern.size()  == str.size()-1) {
      tmp_str_pattern = str_pattern + "0";
      PrintString(str, tmp_str_pattern);
      tmp_str_pattern = str_pattern + "1";
      PrintString(str, tmp_str_pattern);
      return;
   }

   tmp_str_pattern = str_pattern + "0";
   PrintCombinationUtil(str, tmp_str_pattern);
   tmp_str_pattern = str_pattern + "1";
   PrintCombinationUtil(str, tmp_str_pattern); 

   return;
}

void PrintCombination(string str) {
  string str_pattern("");
  PrintCombinationUtil(str, str_pattern);
  return;
}
#endif

/***** Method-2 (Typical recursive method) *************/
/* Suppose string is "abc"
 * "" -> "" + A -> "" + A + B
 *              -> "" + A + C
 *    -> "" + B -> "" + B + C
 *    -> "" + C
 */

#if 1

void PrintCombinationUtil(string str, int index, string tmp_str)
{
   if(tmp_str.size() <= str.size()) {
      cout<<tmp_str<<endl;
   }

   if(index >=  str.size()) {
     return;
   }

   for(int i = index; i < str.size(); i++) {
        PrintCombinationUtil(str, i+1, tmp_str + str.at(i));
   }

   return;
}
void PrintCombination(string str)
{
   PrintCombinationUtil(str, 0, "");
}

#endif
int main()
{
  string str;
  cout << "Enter the string: "<<endl;
  cin>>str;
  PrintCombination(str);
  return 0;
}
