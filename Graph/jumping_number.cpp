/*************** Find number of jumping number [1 to 1000] ******************/
/* In any number, for all the digits, if difference between left digit and current digit == 1 and
 * difference between right digit and current digit == 1
 * then that number is called jumping number */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int jumping_number_count = 0;

void GetJumpingNumberCount(int num, int low_range, int high_range) {
    // extract the last digit of number
    int last_digit = num % 10;
    int new_number;
    if(last_digit < 9 ) {
       new_number = num*10+last_digit+1;
       if(new_number >= low_range && new_number <= high_range) {
          cout<<"Jumping Number is - "<< new_number<<endl;
          jumping_number_count++;
          GetJumpingNumberCount(new_number, low_range, high_range);
       }
    }
    if(last_digit > 0 ) {
       new_number = num*10+last_digit-1; 
       if(new_number >= low_range && new_number <= high_range) {
          cout<<"Jumping Number is - "<< new_number<<endl;
          jumping_number_count++;
          GetJumpingNumberCount(new_number, low_range, high_range);
       }
    }
    return; 
}

int main()
{
   for(int i = 1; i <= 9; i++) {
       GetJumpingNumberCount(i, 1, 1000);
   }
   cout<<"Total Jumping number count between 1 to 1000 is : "<<jumping_number_count<<endl;
   return 0;
}
