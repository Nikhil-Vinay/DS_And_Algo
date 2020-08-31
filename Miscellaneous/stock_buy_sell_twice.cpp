/***** A day-to-day stock price series is given in array [1..N] for n day. Find the maximum profit can be 
 * achieved by two times buy and sell combination of a stock. Second buy will occur always after first sell **/

/** First go through one time buy and sell problem ***.
 *
 * Soln: We will find out by creating profit array in forward direction and backward direction
 * .
 * Stock price array = 350 360 300 330 350 180 200 220 220
 * Profit forward[F] =  0   10  0   30  50  0   20  40  40
 * Profit backward[B]=  10   0  50  20  0   40  20   0   0
 * 2 Buy-Cell Profit =  10  10  60  20  30  90  20  20  40  B[i] + F[i-1]
 * Here if we'll see closely, max profit is 90 at 6th day. If we'll rely on the profit array gives correct
 * data at all indexes then it's wrong as profit should be 70 at seventh day. But, max profit index will have
 * always correct value. 
 *
 * Time complexity = O(N).
 * Brute force time complexity = O(N4)
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
