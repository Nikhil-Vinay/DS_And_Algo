/************** Prims Algorithm to find minimum spanning tree ***************/

/* It is greedy algorithm.
 * Prims algorithm is used to find minimum spanning tree on weighted undirected graph.
 *
 * We know minimum spanning tree has total number of edges = number of vertices - 1.
 *
 * As per this algorithm, first we pick any one vertex and then onwards always pick the least weighted edge 
 * connected to the vertices picked till the moment.
 *
 * Step-1: Initialize each vertex with rank 0 and parent [infinity - int_max]
 * Step-2: Pick any one vertex because all has rank 0.
 * Step-3: Update the rank of adjascent vertices based on the edge weight.
 * Step-4: Pick the adjascent edge with minimum weight (choose the minimum ranked vertex which will have parent
 *         also corresponding to the min wighted edge). Add in the mst array and delete the vertex. 
 *
 * Note: we dont need to worry about cycle here becasue we have a boolean visited array which is updated once
 *       we select a vertex so no edge is picked whose both vertices are visited.
 *
 *
 * Reference: Bo - Qian Video
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph
{
   public:
   int V;
   list<pair<int, int> > *elist;
};

Graph* CreateGraph(int inV)
{
   Graph* g = new Graph();
   g->V = inV;
   g->elist = new list<pair<int, int> >[inV];
}

void AddEdge(Graph* g, int u, int v, int weight)
{
  g->elist[u].push_back(pair<int, int>(v, weight));
//  g->elist[v].push_back(pair<int, int>(u, weight));
}

void Prims(Graph* g, vector<pair<int, int> >& mst)
{
  int v = g->V;
  
  // create an array to store the disjoing sets
  int * parent = new int[v];
  bool * visited = new bool[v];
  int * rank = new int[v];
  // we have a map (key - rank, val - pair <vertex,  parent>
  for(int i = 0; i < v; i++) {
     parent[i] = i;
     visited[i] = false;
     rank[i] = INT_MAX; 
  }

  rank[0] = 0;  // we can pick anyone
  parent[0] = -1;
  
  for(int i = 0; i < v; i++) {
     // find the minimum rank vertex from rank array
     int u = -1;
     for(int i = 0; i < v; i++) {
        if( !visited[i] && ((u == -1)?true:(rank[i] < rank[u]))) {
           u = i;
        }
     } 

     visited[u] = true;

     // add the picked edge to mst
     if( parent[u] != -1) { 
        mst.push_back(pair<int, int>(parent[u], u));
     }

     list<pair<int, int> >::iterator it;
     // update all adjascent edge vertices rank and parent
     for(it = g->elist[u].begin(); it != g->elist[u].end(); it++) {
        int v = it->first;
        int wt = it->second;
        if (!visited[v] && wt < rank[v]) {
           rank[v] = wt;
           parent[v] = u;
        }
     }
  }
}

int main()
{
  int v = 8;
  Graph* g = CreateGraph(v);
  AddEdge(g, 0, 1, 1);
  AddEdge(g, 0, 2, 7);
  AddEdge(g, 2, 3, 2);
  AddEdge(g, 1, 3, 5);
  AddEdge(g, 1, 4, 6);
  AddEdge(g, 4, 6, 9);
  AddEdge(g, 4, 5, 3);
  AddEdge(g, 5, 7, 8);
  AddEdge(g, 6, 7, 4);

  vector<pair<int, int> > mst;  // vector of edges to store mst
  Prims(g, mst);

  // print mast
  vector<pair<int, int > >::iterator it;
  for(it = mst.begin(); it != mst.end(); it++) {
     cout<<"mst edge is: "<<it->first<<","<<it->second<<endl;
  }
  return 0;
}
