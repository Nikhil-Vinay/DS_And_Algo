/* Given a number represented by a list of digits, find the next greater permutation of a number, in terms of lexicographic ordering. If there is not greater permutation possible, return the permutation with the lowest value/ordering.
 *
 * For example, the list [1,2,3] should return [1,3,2]. The list [1,3,2] should return [2,1,3]. The list [3,2,1] should return [1,2,3]
 */

/* Solution:
 * 1. If digits are in descending order, no permutation is possible.
 * 2. If digits are in descending order, just swap of last two digits will make next bigger permutation.
 * 3. Else, start from last digit to find the first smaller digit comapared to last digit.
 *    once you find, swap the digit after smaller one with last digit
 *    sort in ascending order rest digits after the last digit's new position.
 *
 * Ex: Number is: 15897
 *     1. start from 7(last digit), first digit smaller that 7 is 5 then insert 7 after 5.
 *     2. For inserting 7, just swap 8 (digit after 5) with 7 (15798)
 *     2. sort digits after 7 (15789)
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void NextPermutation(string digits)
{
   int len = digits.length();
   char last_digit = digits[len-1];
   int idx = len-1;
   bool found = false;
   while (idx >= 0) {
      if(digits[idx] < last_digit) {
         found = true;
         break;
      }
      idx--;
   }

   if (found) {
      // swap
      digits[idx+1] = digits[idx+1]^digits[len-1];
      digits[len-1] = digits[idx+1]^digits[len-1];
      digits[idx+1] = digits[idx+1]^digits[len-1];

      string::iterator start = digits.begin();
      sort(start + idx+1, digits.end());
      cout<<"Next Permutation is: "<<digits<<endl;
   }  else {
      cout<<"Next Permutation is not found"<<endl;
   }
}

int main()
{
   string digits = "15897";
   NextPermutation(digits);
   return 0;
}
