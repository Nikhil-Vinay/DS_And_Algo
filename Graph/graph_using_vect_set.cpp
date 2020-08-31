/*** Graph representation is very important to solve the competitive programs **/
/** Mostly we use adjacency list representaion for graph implementaion as adjacency matrix is expensive
 * in terms of space in case of parse matrix */
/* We have two methods for adjacency list representaion below mentioned:
 * Method-1 (Using vector/array): Here adjacency list is represented by a vector but it takes O(n) time in 
 * serching for whether an edge exists between two nodes or not.
 *
 * Method-2 (Using set) : Here adjacency list is represented by a set and it takes o(logn) time in searching
 * for whether an edge exists between two nodes or not.
 *
 * Note: If we use unordered_set instead of set then it will take O(1) time in searching for whether an edge
 * exists between two nodes or not.
 */

/* Qn: Why adjacency list is more useful than adjacency matrix.
 * Ans: 
 * Adjacency matrix has O(vxv) time complexity for DFS though adjacency list has O(v+E) time complexity.
 *
 * Adjacency matrix srores the values in a matrix which is represented by indexes 0...N.
 * Graph node representation can be for anything say for example different cities can be represented as graph
 * . In this case each cities will have to be represented by an integer (0...N) for adjacency matrix.
 *
 * Though in case adjacency list it can be represented easily. we can achieve same O(1) time to check edge value
 * between two cities similar to adjacency matrix. [by using unordered_map and unordered_set]
 *
 * struct Graph
 * {
 *    int V;  // number of nodes
 *    unordered_map < string, unordered_set <string> > list;   // string for city names
 * };
 *
 * Graph *g = new Graph();
 * g->list["Patna"].insert("Ranchi");
 * g->list["Patna"].insert("Kolkata");
 * g->list["Patna"].insert("Delhi");
 *
 * string origin = "Patna";
 * string dest = "Kolkata";
 *
 * if((g->list.find(origin) != g->list.end()) && (g->list[origin].find(dest) != g->list[origin].end())) {
 *    cout<<"found"<<endl;
 * } else {
 *    cout<<"not found"<<endl;
 * }
 *
 * Note: If normal set/map is used the time complexity of above code is log(N) X log(N) 
 *       If unordered_set/unordered_map then time complexity is - O(1) x O(1) = O(1)
 */ 

#include<iostream>
#include<bits/stdc++.h>

#define USING_ARRAY 0
#define USING_SET 1

using namespace std;

#if USING_ARRAY
struct Graph
{
   int V;
   vector<int> *adjList;
};

Graph* CreateGraph(int N)
{
   Graph *g = new Graph();
   g->V = N;
   g->adjList = new vector<int> [N];
   return g;
}

void AddEdge(Graph* g, int E1, int E2)
{
   g->adjList[E1].push_back(E2);
   g->adjList[E2].push_back(E1);
}

void PrintGraph(Graph* g)
{
   vector<int>::iterator it;
   for(int i = 0; i < g->V; i++) {
      for(it = g->adjList[i].begin(); it != g->adjList[i].end(); it++) {
         cout<<i<<" and "<<*it<<endl; 
      }
  }
}
#endif

#if USING_SET
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

void AddEdge(Graph* g, int E1, int E2)
{
   g->adjList[E1].insert(E2);
   g->adjList[E2].insert(E1);
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
#endif

int main()
{
   Graph* g = CreateGraph(6);
   AddEdge(g, 0, 1);
   AddEdge(g, 0, 2);
   AddEdge(g, 0, 4);
   AddEdge(g, 1, 5);
   AddEdge(g, 1, 3);
   AddEdge(g, 5, 3);
   PrintGraph(g);
   return 0;
}
