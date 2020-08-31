/*** Find mother vertex in a directed graph **/
/* A mother vertex in a graph G = (V,E) is a vertex v such that all other vertices in G can be reached by a path from v.
 
This problem can be solved using DFS(https://www.geeksforgeeks.org/find-a-mother-vertex-in-a-graph/) with below steps:
1. Find last visited node in DFS (If graph has any mother vertex then last visited node will be mother vertex
   as all nodes are reachable from mother vertex)
2. There might be case that graph doesn't have any mother vertex so, we need to cross check by DFS if all nodes
   are reachable by last visited node. If yes then the last visited node is mother vertex else no mother vertex 
   exist in the grpah.
   Time complexity of this approach os O(V+E) + O(V+E) ~ 2 O(V+E) ~ O(V+E)

The below solution is also using DFS to solve this problem but it executes DFS only one time and as soon as it
gets the mother vertex, it stops the execution. Time complexity is O(V+E) only.
Approach:
1. While executing the DFS, we have a bit mask array representing a bit mask for each node. This bit mask array
   is passed to nodes while execution.
2. Each node modifies their dedicated bit mask in such a way the all set bits represent the nodes can be visited
   from this node including the current node.
3. At each iteration, we check if all nodes can be visited from this node by checking current node's bitmask
   value (if all bits representing to all nodes are set to 1). If all nodes can be visited from this node then
   it breaks the execution.
4. If node B is visited from node A and node B is already visited then node A simply updates it's bitmask by 
   doing OR operation with set own set bit index to node B's bitmask.
*/

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
   for (int i = 0; i < g->V; i++) 
   {
      for (it = g->adjList[i].begin(); it != g->adjList[i].end(); it++) 
      {
          cout<<"There is an edge from "<<i<<" to "<<*it<<endl; 
      }
   }
}

bool IsEdge(Graph* g, int src, int dest)
{
   if (g->adjList[src].find(dest) != g->adjList[src].end()) 
   {
      return true;
   }
   return false;
}

int MotherVertexUtil(Graph *g, int index, int *mask, int *m_vertex)
{
   // if mother vertex is already found then simply return with existing mask of the vertex index
   if (*m_vertex != -1)
   {
      return mask[index];
   }
   
   // if vertex is already visited, return the mask value of this vertex.
   if (mask[index] != 0) 
   {
      return mask[index];
   }

   int tmpmask = 0;
   tmpmask |= (1<<index);
   for (int i = 0; i < g->V; i++) 
   {
      if ((index != i ) && IsEdge(g, index, i)) 
      {
          if (mask[i] == 0) 
          {
             int retmask = MotherVertexUtil(g, i, mask, m_vertex);
             tmpmask |= retmask;
          } else 
          {
             tmpmask |= mask[i];
          }
 
          // check if current vertex is mother vertex or mother vertex is already found
          if (tmpmask == (pow(2, g->V)-1))
          {
             if (*m_vertex == -1) // current vertex is mother vertex
             {
                *m_vertex = index;
             }
             return tmpmask;
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
   for (int i = 0; i < v; i++) 
   {
      mask[i] = 0;
   }

   // DFS
   int tmpmask = 0;
   int m_vertex = -1;
   for (int index = 0; index < v; index++) 
   {
       tmpmask = (1 << index);
       if (mask[index] == 0) 
       {
          int retmask = MotherVertexUtil(g, index, mask, &m_vertex);
          tmpmask |= retmask;
       }

       // check if current vertex is mother vertex or mother vertex is already found
       if (tmpmask == (pow(2, v)-1))
       {
          if (m_vertex == -1) // current vertex is mother vertex
          {
             m_vertex = index;
          }
          break;
       }
       mask[index] |= tmpmask;
   }

   return m_vertex;
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
   PrintGraph(g);

   int m_vertex = MotherVertex(g);
   if (m_vertex == -1)
   {
       cout<<"Mother vertex is not existing in this graph"<<endl;
   }
   else {
       cout<<"Mother vertex is: "<<m_vertex<<endl;
   }
   return 0;
}

// This code is contributed by Nikhil Vinay
