/************** Topological Sorting in Graph ***************/

 /*
 *Topological sorting of vertices of a directed acyclic graph (DAG) is a linear ordering of the vertices in such
  a way that if there is an edge in DAG going from vertex u to vertex v the u comes before v in the ordering.
 * 
 * Topological sort is only possible if graph is directed and acyclic.
 *
 * There could be more than one topological ordering possible for DAG.
 *
 * 1. Scheduling jobs from the given definition among jobs.
 * 2. Instruction scheduling.
 * 3. Data serialization.
 * 4. Determining the order of combination task to perform in makefiles.
 *
 * Method-1: For understanding on paper:
 * 1. write down all vertices inorder then pick the vertices which has 0 inorder and remove this vertex and all 
 *    the outgoing edges from this vertex and after removing the edges, update the inorder of rest vertices and
 *    repeat the same till no vertex is pending.
 * 2. If two or more vertices has 0 inorder the pick any one, this is how multile inorder exists.
 *
 * Method-2: This is coding method using DFS.
 * 1. Pick any vertex and keep traversing to its adjacent vertices if vertices doesn't has any adjascent to visit
 * then push the vertex in stack.
 * 2. Keep marking the vertex as visited once it is visited.
 * 3. Repeat the steps till all vertices are visited.
 * 4. Display the stack elements as toppological ordered elements.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph
{
   public:
   int V;
   list<int> *elist;
};

Graph* CreateGraph(int inV)
{
   Graph* g = new Graph();
   g->V = inV;
   g->elist = new list<int>[inV];
}

void AddEdge(Graph* g, int u, int v)
{
  // Directed Graph
  g->elist[u].push_back(v);
}

void TopologicalUtil(Graph* g, int i, bool*& visited, stack<int> &st)
{
   visited[i] = true;
   list<int>::iterator it;
   for(it = g->elist[i].begin(); it != g->elist[i].end(); it++) {
      if(visited[*it] == false) {
         TopologicalUtil(g, *it, visited, st);
      }
   }
   st.push(i);
}

void TopologicalOrdering(Graph* g, int v)
{
  stack<int> t_stack;  // stack to store topological ordering
  bool* visited = new bool[v];
  for(int i = 0; i < v; i++) { 
     visited[i] = false;
  }

  for(int i = 0; i < v; i++) {
     if(visited[i] == false) {
        TopologicalUtil(g, i, visited, t_stack);
     }
  }

   // Print topological Ordering
   while(!t_stack.empty()) {
      int x = t_stack.top();
      t_stack.pop();
      cout<<x<<" ";
   }
   cout<<endl;
}

int main()
{
  int v = 6;
  Graph* g = CreateGraph(v);
  AddEdge(g, 5, 2); 
  AddEdge(g, 5, 0); 
  AddEdge(g, 4, 0); 
  AddEdge(g, 4, 1); 
  AddEdge(g, 2, 3); 
  AddEdge(g, 3, 1);

  TopologicalOrdering(g, v); 
  return 0;
}
