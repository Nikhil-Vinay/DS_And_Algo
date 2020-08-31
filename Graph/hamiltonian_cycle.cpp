/*********************** Hamiltonian Path ********************************/
 
/* Hamiltonian Path in an undirected graph is a path that visits each vertex exactly once. A Hamiltonian cycle 
 * (or Hamiltonian circuit) is a Hamiltonian Path such that there is an edge (in the graph) from the last vertex 
 * to the first vertex of the Hamiltonian Path. Determine whether a given graph contains Hamiltonian Cycle or not
 * . If it contains, then prints the path. Following are the input and output of the required function.

For example, a Hamiltonian Cycle in the following graph is {0, 1, 2, 4, 3, 0}.

(0)--(1)--(2)
 |   / \   |
 |  /   \  | 
 | /     \ |
(3)-------(4)
And the following graph doesn’t contain any Hamiltonian Cycle.

(0)--(1)--(2)
 |   / \   |
 |  /   \  | 
 | /     \ |
(3)      (4) 

*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph
{
   public:
   int V;   // number of nodes
   list<int> *e_list;   // edge lits
};

Graph* CreateGraph(int v)
{
   Graph *g = new Graph();
   g->V = v;
   g->e_list = new list<int> [v]; 
   return g; 
}

void AddEdge(Graph *g, int u, int v)
{
   g->e_list[u].push_back(v);
   g->e_list[v].push_back(u);
}

bool HamiltonianUtil(Graph *g, int *path, int *mask, int u)
{
   // cycle achieved
   if (u == 0 && *mask == (pow(2, g->V)-1)) { 
      return true;
   }

   list<int>::iterator it;
   for(it = g->e_list[u].begin(); it !=  g->e_list[u].end(); it++) {
      int v = *it;

      path[u] = v;
      if( (v != 0) && (*mask & (1 << v))) {  // if v is not 0 (source) and already visited
         continue;
      } 

      *mask |= (1 << v);
      bool ret = false;
      // if v == 0 then check for cycle
      if ((v == 0)  && (*mask == (pow(2, g->V)-1))) {
          return true;
      }
     
      // if v != 0 then only move in DFS
      if (v != 0) {
         ret = HamiltonianUtil(g, path, mask, v);
         if (ret) {
            return ret;
         }
      }
     
       // back tracking
       path[u] = -1;
       *mask ^= (1 << v);
   } 

   return false;
}
 
void PrintHamiltonianPath(Graph *g)
{
   int V = g->V;
   int *path = new int[V];
   for(int i = 0; i < V; i++) {
      path[i] = -1;
   }
   int mask = 0;
 
   // DFS
   // for hamiltonian path all vetices should be connected. so no need to have a for loop
   // chack for only vertex 0
   path[0] = 0;
   mask |= (1<<0);

   bool ret = HamiltonianUtil(g, path, &mask, 0);
 
   if(ret) {
     cout<<"Hamiltonian path exists"<<endl;
     int i = 0;
     cout<<"0";
     while( path[i] != 0) {
        cout<<" -> ";
        cout<<path[i];
        i = path[i];
     }
     cout<<" -> "<<path[i]<<endl;
   } else {
     cout<<"Hamiltonian path is not possible"<<endl;
   }
}

int main()
{
   Graph *g1 = CreateGraph(5);
   AddEdge(g1, 0, 1);
   AddEdge(g1, 0, 3);
   AddEdge(g1, 1, 2);
   AddEdge(g1, 1, 3);
   AddEdge(g1, 1, 4);
   AddEdge(g1, 2, 4);
   AddEdge(g1, 3, 4);
   
   PrintHamiltonianPath(g1); 

   Graph *g2 = CreateGraph(5);
   AddEdge(g2, 0, 1);
   AddEdge(g2, 0, 3);
   AddEdge(g2, 1, 2);
   AddEdge(g2, 1, 3);
   AddEdge(g2, 1, 4);
   AddEdge(g2, 2, 4);
   
   PrintHamiltonianPath(g2);
 
   return 0;
}
