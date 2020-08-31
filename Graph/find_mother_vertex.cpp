/*** Find mother vertex in a directed graph **/
/* A mother vertex in a graph G = (V,E) is a vertex v such that all other vertices in G can be reached by a path from v */

/* There is a simple solution of this problem using DFS is the last node visited in DFS will be mother vertex
 * because all nodes are reachable for mother vertex so once mother vertex will be visited, DFS will end up.
 * But after this, we need to cross check if the last vertex is really a mother vertex because there could be
 * possibilities as graph doesn't have any mother vertex.
 *
 * The below solution is created by me, it's very useful in solving some other similar kind of problem */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Graph
{
   int V;
   set<int, greater<int> > *adjList;   // store in descending order
};

Graph* CreateGraph(int N)
{
   Graph *g = new Graph();
   g->V = N;
   g->adjList = new set<int, greater<int> > [N];
   return g;
}

void AddEdge(Graph* g, int src, int dest)
{
   g->adjList[src].insert(dest);
}

void PrintGraph(Graph* g)
{
   set<int, greater<int> >::iterator it;
   for(int i = 0; i < g->V; i++) {
      for(it = g->adjList[i].begin(); it != g->adjList[i].end(); it++) {
         cout<<i<<" and "<<*it<<endl; 
      }
  }
}

bool IsEdge(Graph* g, int src, int dest)
{
   if(g->adjList[src].find(dest) != g->adjList[src].end()) {
      return true;
   }
   return false;
}

int MotherVertexUtil(Graph *g, int index, int *mask)
{
   if(mask[index] != 0) {
      return mask[index];
   }

   int tmpmask = 0;
   tmpmask |= (1<<index);
   for(int i = 0; i < g->V; i++) {
      if( (index != i ) && IsEdge(g, index, i)) {
          if(mask[i] == 0) {
             int retmask = MotherVertexUtil(g, i, mask);
             tmpmask |= retmask;
          } else {
             tmpmask |= mask[i];
          }   
      }
   }
   mask[index] |= tmpmask;
   return mask[index];    
}

int MotherVertex(Graph *g)
{
   int v = g->V;
   int *mask = new int(v);
   for(int i = 0; i < v; i++) {
      mask[i] = 0;
   }

   // DFS
   int tmpmask = 0;
   for(int index = 0; index < v; index++) {
       tmpmask = (1 << index);
       if(mask[index] == 0) {
          int retmask = MotherVertexUtil(g, index, mask);
          tmpmask |= retmask;
       }
       mask[index] |= tmpmask;
   }

   // Check for mother vertex
   int mother_vertex = -1;
   for(int i = 0; i < v; i++) {
      if(mask[i] == (pow(2, v)-1)) {
         mother_vertex = i;
         break;
      }
   }
   return mother_vertex;
}

int main()
{
   Graph* g = CreateGraph(7);
   AddEdge(g, 0, 2);
   AddEdge(g, 0, 1);
   AddEdge(g, 1, 3);
   AddEdge(g, 4, 1);
   AddEdge(g, 5, 2);
   AddEdge(g, 5, 6);
   AddEdge(g, 6, 0);
   AddEdge(g, 6, 4);
//   PrintGraph(g);

   cout<<"Mother Vertex is: "<<MotherVertex(g)<<endl;
   return 0;
}
