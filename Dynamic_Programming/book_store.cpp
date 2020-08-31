/* There is a book store. It has N books at self and each book has some price. You need to buy all the books from 
 * the self. The rule of buying a book is  as follows:
 * 1. If you buy a book at index i then total price will be price[i-1]*price[i]*price[i+1].
 *    Price of current book will be multiplied by adjascent book.
 * 2. Once a book at index i  is bought then i-1 and i+1 th book becomes adjascent to each other.
 * 3. If a book is bought at boundary (0th or n-1th index) then the missing adjascent will be considered as 1.
 *
 * We need to find the maximum cost one can incur while buying all books from the self.
 *
 * Example: prices[2] = [1,2]
 * first buy book at index 0 = 1*1*2 = 2
 * next buy at index 1 = 1*2*1 = 2  
 * Total cost = 2 + 2 =4
 *
 * If we will buy in reverse order then total cost would be 2
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int dp[100][100];

int MaxPrice(vector<int> &price, int left, int right)
{
   if(right - left <= 1) {
      return 0;
   }

   if(dp[left][right] != -1) {
      return dp[left][right];
   }

   int ans = 0;
   // calculate considering each book at index i is sold at last.
   for(int i = left+1; i < right; i++){
      ans = max(ans, price[left]*price[i]*price[right] + MaxPrice(price, left, i) + MaxPrice(price, i, right));
   }
   dp[left][right] = ans;
   return ans;
}


int main()
{
   int n;
   cout<<"Enter the number of books: "<<endl;
   cin>>n;
   vector<int> price;
   price.reserve(n+2);
   // setting boundaries price with 1
   price[0] = 1;
   price[n+1] = 1;
   for(int i= 1; i <= n; i++) {
       cin>>price[i];
   }

   memset(dp, -1, sizeof dp);
   cout<<"Maximum Price of buying all books is: "<<MaxPrice(price, 0, n+1)<<endl;
   return 0;
}
