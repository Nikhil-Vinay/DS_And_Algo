/* Given the mobile numeric keypad. You can only press buttons that are up, left, right or down to the current button.
   You are not allowed to press bottom row corner buttons (i.e. * and # ).
   
          1   2   3
          4   5   6
          7   8   9
              0
   
   Given a number N, find out the number of possible numbers of given length.
 */
 
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n = 2;  // numbers of moves/press 

	vector<vector<int>> moves;
	moves.reserve(10);
	moves[0] = {0, 8};
	moves[1] = {1,2,4};
	moves[2] = {2,1,3,5};
	moves[3] = {3,2,6};
	moves[4] = {4,1,7,5};
	moves[5] = {5,2,4, 6, 8};
	moves[6] = {6,3,5,9};
	moves[7] = {7,8,4};
	moves[8] = {8,7,5,9,0};
	moves[9] = {9,8,6};

    int** dp = new int*[n+1];
    for(int i = 0; i <= n; i++){
    	dp[i] = new int[10];
    }
    
    for(int i = 1; i <= n; i++ ){
    	for(int j = 0; j <= 9; j++){
    		if( i == 1){
    			dp[i][j] = 1;
    		} else {
    		    for(int x: moves[j]){
    		    	dp[i][j] += dp[i-1][x];
    		    }
    		}
    	}
    	      
    }
    
    int count = 0;
    for(int i = 0; i <= 9; i++){
    	count += dp[n][i];
    }
    
    cout<<"Total count of possible numbers of length "<<n<<" is "<<count<<endl;
}
