/* Given a square chessboard of N x N size, the position of Knight and position of a target is given. We need to find out minimum steps a Knight will take to reach the target position. */

/* Note: Whenever problem comes from chess board, snake ladder etc for finding minimum number of steps to reach
 * or finding shortest path, think for BFS. BFS might be best solution for that.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// There are 8 directions from any position for knight jump
#define MAX_JUMP_COUNT 8
int jump_offset_x[MAX_JUMP_COUNT] = { -1, 1, -2, -2, -1,  1, 2,  2}; 
int jump_offset_y[MAX_JUMP_COUNT] = {  2, 2,  1, -1, -2, -2, 1, -1};

typedef struct pos_s
{
  int x;
  int y;
  int count;
  pos_s(): x(0), y(0), count(0) { }
  pos_s(int in_x, int in_y, int in_count):x(in_x), y(in_y), count(in_count) { }
}pos;

bool IsValid(int n, int next_x, int next_y) {
   if(next_x < 1 || next_x > n || next_y < 1 || next_y > n ) {
     return false;
   }
 
   return true;
}

int GetMinHopCount(int n, int cur_pos_x, int cur_pos_y, int final_pos_x, int final_pos_y)
{
   int count = 0;
   // We need to traverse by BFS to get min number of hops. similar to finding shortest path
   int** visited = new int*[n+1];
   for(int i = 0; i <= n; i++) {
      visited[i] = new int[n+1];
   }

   for(int i = 0; i <= n; i++) {
      for(int j = 0; j <=n; j++) {
          visited[i][j] = 0;
      }
   }

   queue<pos> que;
   que.push(pos(cur_pos_x, cur_pos_y, 0));
   visited[cur_pos_x][cur_pos_y] = 1;

   while(!que.empty()){
      pos cur = que.front();
      que.pop();
      // visit in all 8 directions
      for(int i = 0; i < MAX_JUMP_COUNT; i++) {
         int next_x = cur.x  +  jump_offset_x[i];
         int next_y = cur.y  +  jump_offset_y[i];
         if(next_x == final_pos_x && next_y == final_pos_y) {
            return cur.count+1;
         }
         if(IsValid(n, next_x, next_y) && visited[next_x][next_y] == 0 ) {
           visited[next_x][next_y] = 1;
           que.push(pos(next_x, next_y, cur.count+1));
         }
      }
   }
   return -1;  // if not possible
}

int main()
{
   int n = 30;
   int cur_pos_x = 1;
   int cur_pos_y = 1;
   int final_pos_x = 30;
   int final_pos_y = 30;

   cout<<"Minimum knight hop count is: "<<GetMinHopCount(n, cur_pos_x, cur_pos_y, final_pos_x, final_pos_y)<<endl;
}
