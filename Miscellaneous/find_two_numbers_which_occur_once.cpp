/* Given an array of integers in which two elements appear exactly once and all other elements appear exactly twice, find the two elements that appear only once.
 *
Sol-1: Sort all numbers and traverse in sorted array to find - O(nlogn).
Sol-2: Below Solution:
 * For example, given the array [5, 2, 3, 5], return 2 and 2.
   This is very good combination for dry run */
   

#include<iostream>
#include<bits/stdc++.h>
#define EXTRACT_LAST_SET_BIT(n) n&(-n)

using namespace std;
  
/* This finction sets the values of  
*x and *y to nonr-epeating elements 
in an array arr[] of size n*/
void get2NonRepeatingNos(int arr[], int n, int *x, int *y)  
{  
    int Xor = arr[0]; /* Will hold Xor of all elements */
    int set_bit_no; /* Will have only single set bit of Xor */
    int i;  
    *x = 0;  
    *y = 0;  
      
    /* Get the Xor of all elements */
    for(i = 1; i < n; i++)  
    Xor ^= arr[i];  
      
    /* Get the rightmost set bit in set_bit_no, we can use any set bit number */
    set_bit_no = EXTRACT_LAST_SET_BIT(Xor);  
      
    /* Now divide elements in two sets by comparing rightmost set  
    bit of Xor with bit at same position in each element. */
    for(i = 0; i < n; i++)  
    {  
        if(arr[i] & set_bit_no)  
        *x = *x ^ arr[i]; /*Xor of first set */
        else
        *y = *y ^ arr[i]; /*Xor of second set*/
    }  
}  
  
/* Driver code */
int main()  
{  
    int arr[] = {2, 3, 7, 9, 11, 2, 3, 11};  
    int *x = new int[(sizeof(int))];  
    int *y = new int[(sizeof(int))];  
    get2NonRepeatingNos(arr, 8, x, y);  
    cout<<"The non-repeating elements are "<<*x<<" and "<<*y<<endl;  
}  
  
