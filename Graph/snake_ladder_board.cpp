/*********** Snake Ladder Board (An interesting problem on graph) ***********************/
/** There is a snake ladder board (6 X 6 ). It has some snakes and ladders as usual at some numbers. We need
 *  * to find the minimum number of dice throw to reach 36 from 1. One throw of dice can get you min -1 and max - 6.

  Solution, First we will make an undirected unweighted graph then, we will sove it by BFS.
  There is a board array which will have information about snake and ladder.
  Ex: board[2] = 13 means there is ladder at index 2 which will take to 2 + 13 = 15.
      board[17] = -13 means there is a ladder at index 17 which taks to 17-13 = 4.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Adj List Implementation for Integer Nodes
class Graph{
  int V;	
  //Array of Linked Lists of size V, V LL's are there
  list<int> *adjList;
public:
  Graph(int v){
     V = v;
     adjList = new list<int>[V];
  }
  void addEdge(int u,int v,bool bidir=true){  // bidir = true for undirected graph
     adjList[u].push_back(v);
     if(bidir){
     	adjList[v].push_back(u);
     }
  }
  
  void printAdjList() {
       list<int>::iterator it;
       for(int i=0;i<V;i++){
     	   cout<<i<<"->";
     	   //for(int node:adjList[i]){
     	   for(it = adjList[i].begin(); it != adjList[i].end(); it++){
     	       cout<<*it<<",";
     	   }
     	   cout<<endl;
       }
  }

  void bfs(int src,int dest){
       //Traverse all the nodes of the graph
       queue<int> q;
       //bool *visited = new bool[V+1]{0};
       //int *dist = new int[V+1]{0};
       bool *visited = new bool[V+1];
       int *dist = new int[V+1];
       int *parent = new int[V+1];

     	for(int i=0;i<V;i++){
     	   parent[i] = -1;
     	}

     	q.push(src);
     	visited[src] = true;

        list<int>::iterator neighbour;
     	while(!q.empty()){
     	   int node = q.front();
     	   cout<<node<<" ";
     	   q.pop();

     	   //for(int neighbour:adjList[node]){
     	   for(neighbour = adjList[node].begin(); neighbour != adjList[node].end(); neighbour++){
     	       if(!visited[*neighbour]){
     		  q.push(*neighbour);
     		  visited[*neighbour] = true;
     		  dist[*neighbour] = dist[node]  + 1;
     		  parent[*neighbour] = node;
     	       }
     	   }
     	}
     	cout<<endl;
     	//Print the distances of every node from source
     	for(int i=0;i<V;i++){
     		//cout<<i<<"node having dist "<<dist[i]<<endl;
     	}

     	cout<<"Shortest dist is "<<dist[dest]<<endl;
     	cout<<"Shortest path is ";

     	int temp = dest;
     	while(temp!=-1){
     	   cout<<temp<<"<--";
     	   temp = parent[temp];
     	}
     }
};

int main(){
    // There is 6x6 = 36 nodes only but we create graph with sufficienet nodes 50.
    Graph g(50);
    int board[50] = {0};
    memset(board, 0, sizeof(board));

    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;

    // Inser edges
    for(int u = 0; u < 36; u++) {
       // throw a dice from 1 to 6
       for(int dice = 1; dice <= 6; dice++) {
          int v = u + dice + board[u+dice];
          g.addEdge(u, v, false);  // make it directed graph
       }
    }

   // shortes path
   g.bfs(1, 36);
   cout<<endl;

   return 0;
}
