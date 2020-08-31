/* This problem was asked by Apple.
 *
 * Gray code is a binary code where each successive value differ in only one bit, as well as when wrapping around. Gray code is common in hardware so that we don't see temporary spurious values during transitions.
 *
 * Given a number of bits n, generate a possible gray code for it.
 *
 * For example, for n = 2, one gray code would be [00, 01, 11, 10].
 * */

/* Note: Output is similar to binary numbers but ordering is different, as 10 can't come after 01 (two bits get changed). This is the beauty of this question.
 */

/*  Idea is that for each bit out of n bit we have a choice either we can ignore it or we can invert the bit so this means our gray sequence goes upto 2 ^ n for n bits.
 *
 *  Key point is - we need to pass as reference during backtracking. Dry run will make picture clear.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void PrintGreyUtil(string& str, int n)
{
  if(0 == n) {
    cout<<str<<endl;
    return;
  }

  // pass with same bit at index n-1
  PrintGreyUtil(str, n-1);
  // pass after inverting the bit at index n-1
  if(str[n-1] == '0') {
     str.at(n-1) = '1';
  } else {
     str.at(n-1) = '0';
  }
  PrintGreyUtil(str, n-1);
   
}

void PrintGrey(int n)
{
  string str("");
  for(int i = 0; i < n; i++) {
    str += "0";
  }
  PrintGreyUtil(str, n);
}

int main()
{
   int n;
   cout<<"Provide digit count of grey numbers:"<<endl;
   cin>>n;
   cout<<"Grey codes are: "<<endl;
   PrintGrey(n);
   return 0;
}
