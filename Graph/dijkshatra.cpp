/** Dijkshatra Algorithms ***/
/* Shortest path in undirected, weighted and connected graph **/
/* We can use priority queue also for picking min weight always */
/* It is similar to prims MST algorithms */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int GetMinWeightIndex(int* distance, int* visited, int n)
{
   int index = -1;
   for(int i = 0; i < n; i++) {
      if((visited[i] == 0) && ((index == -1) || (distance[i] < distance[index]))) {
         index = i;
      }
   }
   return index;   
}

void prims(int** graph, int n)
{
   int* distance = new int[n];
   int* visited = new int[n];
   int* parent = new int[n];

   for(int i = 0; i < n; i++) {
      distance[i] = INT_MAX;
      visited[i] = 0;
   }

   distance[0] = 0;
   parent[0] = -1;
   int i = 0;
   while(i < n) {
      // find min vertex
      int minvertex = GetMinWeightIndex(distance, visited, n);

      // mark curnode as visited
      visited[minvertex] = 1;
      // update weights of all nodes adjascent to curnode
      for(int k = 0; k < n; k++) {
         if(!visited[k] && graph[minvertex][k] && (distance[k] > (distance[minvertex] + graph[minvertex][k]))) {
             distance[k] = distance[minvertex] + graph[minvertex][k];
             parent[k] = minvertex;
         }
      }
      i++;
   }

   for(int i = 0; i < n; i++) {
      cout<<"shortest distance from 0 to "<<i<<" : "<<distance[i]<<endl;
   }
}

int main()
{
   int n, e;
   cout<<"Enter number of edge:"<<endl;
   cin>>e;
   cout<<"Enter number of vertices:"<<endl;
   cin>>n;
   cout<<"Add edges: v1 v2 w"<<endl;
   int** graph = new int*[n];
   for(int i = 0; i < n; i++) {
       graph[i] = new int[n];
   }

   for(int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         graph[i][j] = 0;
      }
   }

   int u, v, w; 
   for(int i = 0; i < e; i++) {
       cout<<"Enter edge-"<<i<<":"<<endl;
       cin>>u>>v>>w;
       graph[u][v] = w;
       graph[v][u] = w;
   }

   
   prims(graph, n);

   return 0;
}
