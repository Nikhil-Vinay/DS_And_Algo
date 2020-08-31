/***** A day-to-day stock price series is given in array [1..N] for n day. Find the maximum profit can be 
 * achieved by one time buy and one time sell of a stock *************/

/**** 350, 360, 300, 330, 350, 180, 200, 220, 220 ***************/
/* Here maximum stock price is 360 and minimum stock price is 180 but we can's say max profit is (360 -180).
 * We can make any sorting because stock prices are in day by day order, we can't shuffle it.
 * Max profit here is - 50 (350 - 300) (Buy at day2 and sell at day 4).
 *
 * Soln: We will find out by creating min forward array.
 * Stock price array = 350 360 300 330 350 180 200 220 220
 * Min at index i    = 350 350 300 300 300 180 180 180 180
 * Profit at index i =  0   10  0   30  50  0   20  40  40
 *
 * Time complexity = O(N).
 * Brute force time complexity = O(N2)
 *
 * Variant: Find out pair of min and max in an array where max comes always after min and (max-min) would be
 * maximum.
 *
 * Similar: Find out maximum length of subarray which will have same elements.(NlogN by sorting)
 *
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void MaxProfit(int arr[], int size)
{
  int buy_day = 0;
  int sell_day = 0;
  int min_day = 0;
  int min = arr[0];
  int max_profit = 0;
  for(int i = 0; i < size; i++) {
    if(arr[i] < min) {
       min = arr[i];
       min_day = i+1;
    } else {
       if((arr[i] - min) > max_profit) {
          max_profit = (arr[i] - min);
          buy_day = min_day;
          sell_day = i+1;
       }
    }     
  }
  cout<<"Maximum profit is: "<<max_profit<<endl;
  cout<<"Stock will be bought on "<<buy_day<<" and sold on "<<sell_day<<endl; 
}

int main()
{
  int arr[9] = { 350, 360, 300, 330, 350, 180, 200, 220, 220 };
  MaxProfit(arr, 9);

  return 0;
}
