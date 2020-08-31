/**** There ia an array of n integers where every integers occur thrice except one. Find that numebr which
 * occurs one time only  */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/* Take an array of 32 integers which represens the 32 bits of an integer.
 * add all 0...31 bits of integers and store in the array at respective indexes. Now, bits are of numbers
 * appearing three times will have final value as multiple of 3. so. take modulus by 3 on all the elements
 * of the array. Now array will have bit pattern of the number which is occuring only once. 
 *
 * This can be applied on variant of this question as except one integer all other occur n times in array*/

#define EXTRACT_LAST_SET_BIT(n) n&(-n)
#define RESET_LAST_BIT(n) n&(n-1)
//#define LOG_BASE_2(n) (int)(log(n)/(log2))

int GetNumber(vector<int> vct)
{
  int arr[32] = { 0 };
  int bit_index = 0;
  int last_set_bit = 0;
  for(int i = 0; i < vct.size(); i++) {
     while(vct[i]) {
        last_set_bit = EXTRACT_LAST_SET_BIT(vct[i]);
        bit_index = (int)(log2(last_set_bit));
        arr[bit_index]++;
        vct[i] = RESET_LAST_BIT(vct[i]);
     }
  }
  
  int number = 0;
  for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
     if(arr[i]%3) {
        number = number | (1 << i);
     }
  }
  
  return number;
}

int main()
{
  vector<int> vct;
  vct.push_back(5);
  vct.push_back(10);
  vct.push_back(2);
  vct.push_back(8);
  vct.push_back(10);
  vct.push_back(5);
  vct.push_back(2);
  vct.push_back(8);
  vct.push_back(6);
  vct.push_back(10);
  vct.push_back(5);
  vct.push_back(8);
  vct.push_back(2);

  cout<<"number occuring only once : "<<GetNumber(vct)<<endl;

   return 0;
}
