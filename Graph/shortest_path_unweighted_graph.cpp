/********* Find shortest path in unweighted graph ************/
/* Time Complexity = O (V + E) */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph
{
  public:
  int V;            // number of vertex
  list<int> *elist; // edge list
};

Graph* CreateGraph(int V)
{
   Graph* g = new Graph();
   g->V = V;
   g->elist = new list<int> [V];
   return g;
}

void AddEdge(Graph *g, int u, int v)
{
   g->elist[u].push_back(v);
   g->elist[v].push_back(u);
}

bool BFSUtil(Graph *g, int src, int dest, bool *visited, int *path_cost, int* path_pred)
{
   queue<int> q;
   q.push(src);
   visited[src] = true;
   path_cost[src] = 0;

   while(!q.empty()) {
      int u = q.front();
      q.pop();

      list<int>::iterator it;
      for(it = g->elist[u].begin(); it != g->elist[u].end(); it++)
      {
         if(visited[*it] == false) {
            path_cost[*it] = path_cost[u] + 1;
            visited[*it] = true;
            path_pred[*it] = u;
            q.push(*it);
         }

         if(*it == dest) {
           return true;
         }
      }
   }

   return false;
}

void FindShortestPath(Graph *g, int src, int dest)
{
   int V = g->V;
   
   // visited array
   bool *visited = new bool[V];
   // path val array
   int *path_cost = new int[V];
   // path track array
   int *path_pred = new int[V];

   for(int i = 0; i < V; i++) {
      visited[i] = false;
      path_cost[i] = INT_MAX;
      path_pred[i] = -1;
   }

   // BFS
   bool found = false;
   found = BFSUtil(g, src, dest, visited, path_cost, path_pred);

   if(found) {
      cout<<"Shortest path cost between "<<src<< " and "<<dest<<" is "<<path_cost[dest]<<endl;
      cout<<"Shortest path is: ";
      int path = dest;
      stack<int> path_stack;
      path_stack.push(path);
      while(path != src) {
         path = path_pred[path];
         path_stack.push(path);
      }

      while(!path_stack.empty()) {
         int path = path_stack.top();
         path_stack.pop();
         cout<<path;
         if(!path_stack.empty()) {
            cout<<" -> ";
         }
      }
      cout<<endl;
   } else {
       cout<<"There is no path between "<<src<<" and "<<dest<<endl;
   }
}


int main()
{
   int V = 8;
   Graph *g = CreateGraph(V);
   AddEdge(g, 0, 1); 
   AddEdge(g, 0, 3); 
   AddEdge(g, 1, 2); 
   AddEdge(g, 3, 4); 
   AddEdge(g, 3, 7); 
   AddEdge(g, 4, 5); 
   AddEdge(g, 4, 6); 
   AddEdge(g, 4, 7); 
   AddEdge(g, 5, 6); 
   AddEdge(g, 6, 7);
   FindShortestPath(g, 0, 7);
   return 0;
}
