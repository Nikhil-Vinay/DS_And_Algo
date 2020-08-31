/********* There is a given matrix, find a word in the matrix, if present return true **************/

/** Note: Word can be present in 8 directions - Left->Right, Right->Left, Top->Bottom, Bottom->Top, Top-Right(diagonal), Top-Left(Diagonal), Bottom-Right(Diagonal), Bottom-Left(Diagonal).
*/

/* In the below solution , we are just displaying the match count, for displaying the word at proper place,
 * we can have an auxiliary two d matrix of 0 or 1. We can populate matrix with 0 and 1 with each word match and 
 * once full word match, we can display the original matrix with help of auxiliary matrix. 
 * Auxiliary matrix resetting should be done accordingly in serach flow.
 */

#include<iostream>
#include<bits/stdc++.h>
#define DIRECTION_COUNT 8

using namespace std;

int direction_x[DIRECTION_COUNT] = {1, -1, 0, 0, 1, -1, 1, -1};
int direction_y[DIRECTION_COUNT] = {0,  0, 1,-1, 1,  1,-1, -1};
int match_count = 0;

template<size_t M, size_t N>
void FindMatch(char(&matrix)[M][N], const char* word, int x, int y)
{
  for(int i = 0; i < DIRECTION_COUNT; i++) {
     const char* temp_word = word;
     int temp_x = x, temp_y = y;
     while(temp_word[0] != '\0' && matrix[temp_x][temp_y] == temp_word[0] && 
           (temp_x >= 0 && temp_x < N && temp_y >= 0 && temp_y < M)) {
           temp_x += direction_x[i];
           temp_y += direction_y[i];
           temp_word++;
           if(temp_word[0] == '\0') {
              match_count++;
              break;
           }
     }
  }
}

int main()
{
  char matrix[4][4] = { {'a', 'c', 'a', 't' },
                        {'b', 'd', 'a', 'p' },
                        {'t', 'h', 'm', 't' },
                        {'c', 'a', 't', 'x' }};
  const char* word = "thb";

  for(int i = 0; i < 4; i++) {
     for(int j = 0; j < 4; j++) {
        FindMatch(matrix, word, i, j);
     }
  }
 
  cout<<"match count is: "<<match_count<<endl; 
  return 0;
}
