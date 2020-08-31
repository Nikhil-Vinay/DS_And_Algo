/* The below concept is very useful in solving many kind of questions.
 * This is kind of hashing called bit vector hashing
 * We use to hash similary for character array by taking char hash[255].
 * We can use balance BST or map or unordered_map for same wherever hashing is needed to solve */

/* Question pattern :
 * 1. Find out first repeating integer or character in an array.
 * 2. Find out to check if any repeating integer or character present in an array
 * 3. Find out number of repeating integer or characterpresent in an array.
 * 5. Find out in an array is subset of another array
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define BYTE_BIT_COUNT 8

int main()
{
   // to support till 32*4 = 128 integers
   int hash[4] = {0};
   cout << "size if hash is: "<<sizeof(hash)<<endl;
   // number array
   int arr[12] = { 22, 24, 26, 28, 60, 100, 30, 50, 28, 90, 100, 10 }; 
   int bits_per_slot = (sizeof(hash)/sizeof(hash[0]))*BYTE_BIT_COUNT;
   cout<<"bits per slot: "<<bits_per_slot<<endl;
   int i = 0;
   bool first_repeat_found = false;
   // check for first repeating number
   for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
      int slot_idx = arr[i] / bits_per_slot;
      int bit_idx = arr[i] % bits_per_slot;

      cout<<"number = "<<arr[i]<< "slot_idx = "<<slot_idx<<"bit_idx = "<<bit_idx<<endl;
     
      if(!first_repeat_found && ((hash[slot_idx] & (1 << bit_idx)) & (1<<bit_idx))) {
          cout<<"First repeating number is: "<<arr[i]<<endl;
          first_repeat_found = true;
      } else { 
        hash[slot_idx] |= (1 << bit_idx);
      }
   }

   return 0;
}
