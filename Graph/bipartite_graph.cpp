/*********** Check if graph is bipartite ********/

/* Bi-Partite menas Bi Partition , Partition in two section
 * A Bipartite Graph is a graph whose vertices can be divided into two independent sets, U and V such that every 
 * edge (u, v) either connects a vertex from U to V or a vertex from V to U. In other words, for every edge 
 * (u, v), either u belongs to U and v to V, or u belongs to V and v to U. We can also say that there is no edge 
 * that connects vertices of same set.
 *
 * 1. Bipartite graph doesn't have any self loop (Node A has an edge to itself)
 * 2. Disconnected graph can be a bipartite grah.
 * 3. Bipartite graph can have a cycle but it can't have odd number of edges in cycle.
 *    problem: Check if a graph has cycle but it has odd even number of edge in the cycle.
 *             Can be a problem related to check if graph is bipartite.
 *
 */

/* Note: It can be solved by back trakcing but BFS is best approach to solve it. */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph
{
   public:
   int V;
   list<int> *elist;
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

bool IsBipartiteUtil(Graph* g, int *color, int i)
{
   // BFS
   queue<int> q;
   q.push(i);

   while(!q.empty()) {
      int u = q.front();
      q.pop();

      list<int>::iterator it;
      for(it = g->elist[u].begin(); it != g->elist[u].end(); it++) {
         if(*it == u) {
           return false;   // self loop
         }

         if(color[*it] == color[u]) {
            return false;   // neighbour is colored with same color
         }

         if(color[*it] == -1) {   // if not yet colored then color it
            int color_to_do = (color[u] == 1) ? 0 : 1;
            color[*it] = color_to_do;
            q.push(*it);
         }
      }
   }
   return true;
}

bool IsBipartite(Graph* g, int V)
{
   // -1: Not colored, 0: color1, 1:color2
   int *color = new int[V];
   for(int i = 0; i < V; i++) {
      color[i] = -1;
   }

   for(int i = 0; i < V; i++) {
      if(color[i] == -1) {
         color[i] = 0;
         if(!IsBipartiteUtil(g, color, i)) {
            return false;
         }
      }
   }

   return true;
}

int main()
{
   int V = 4;
   Graph* g = CreateGraph(V);
   AddEdge(g, 0, 1);
   AddEdge(g, 0, 3);
   AddEdge(g, 1, 2);
   AddEdge(g, 2, 3);

   bool res = IsBipartite(g, V);
   if(res) {
     cout<<"Graph is bipartite"<<endl;
   } else {
     cout<<"Graph is not bipartite"<<endl;
   }
   return 0;
}
              
