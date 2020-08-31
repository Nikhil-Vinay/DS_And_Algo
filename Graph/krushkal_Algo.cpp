/************** Krushkal Algorithm to find minimum spanning tree ***************/

/* It is greedy algorithm.
 * Krushkal algorithm is used to find minimum spanning tree on weighted undirected graph.
 *
 * We know minimum spanning tree has total number of edges = number of vertices - 1.
 *
 * As per this algorithm, always, minimum weighed edge is picked and checked whether it is forming a cycle or not . If it forms a cycle this edge is not included else included in minimum spanning tree.
 *
 * Note: For detecting whether the picked edge forms cycle or not, we use disjoint set union algorithm.
 * 
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
  //g->elist[v].push_back(pair<int, int>(u, weight));
}

int UpdateDisjointArray(int *& arr, int u, int v)
{
  int ret = 0;
  // check for parent of u
  while(arr[u] > 0){
    u = arr[u];
  }
  int parent_u = u;

  // check for parent of v
  while(arr[v] > 0) {
    v = arr[v];
  }
  int parent_v = v;

  // if both parents are same then return failure (-1)
  if(parent_u == parent_v) {
    return -1;
  } else {  // perform union

    if(abs(arr[parent_u]) > abs(arr[parent_v])) {
       arr[parent_u] = arr[parent_u] + arr[parent_v];
       arr[parent_v] = parent_u;
    } else {
       arr[parent_v] = arr[parent_u] + arr[parent_v];
       arr[parent_u] = parent_v;
    }
  }

  return 0; 
}

void Krushkal(Graph* g, vector<pair<int, int> >& mst)
{
  int v = g->V;
  
  // create an array to store the disjoing sets
  int * darray = new int[v];
  // make each vertex parent of self (root node) with rank -1 
  // - represent the root of tree and 1 represents the total number of node in tree
  for(int i = 0; i < v; i++) {
     darray[i] = -1;
  }

  // store all the edges in a multimap (edge weight as key and edge vertices pair as value).
  // map will store in ascending order so we will keep picking the root element by iterator at begin and will
  // keep deleting the same.
  //
  // we can use heap also but heap will need deleteion after each time popping the min (root) element but
  // map is already sorted so we can just iterate till end.

  multimap<int, pair<int, int> > emap;
  list<pair<int, int> >::iterator it;
  for(int i = 0; i < v; i++) {
     for(it = g->elist[i].begin(); it != g->elist[i].end(); it++) {
        emap.insert(make_pair(it->second, pair<int, int>(i, it->first)));
     }
  }

   // iterate through map and select the edges
   multimap<int, pair<int, int> >::iterator m_it;
   for(m_it = emap.begin(); m_it != emap.end(); m_it++) {
       int u = m_it->second.first;
       int v = m_it->second.second;

       int toSelect = UpdateDisjointArray(darray, u, v);
       if(toSelect == 0) {
          mst.push_back(pair<int, int>(u,v));
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
  Krushkal(g, mst);

  // print mst
  vector<pair<int, int> >::iterator it;
  for(it = mst.begin(); it != mst.end(); it++) {
     cout<<"mst edge is: "<<it->first<<","<<it->second<<endl;
  }
  return 0;
}
