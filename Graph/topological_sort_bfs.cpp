#include<iostream>
#include<map>
#include<list>
#include<queue>

/* Note: Existence of cycle is checked in undirected by DFS but existence of cycle is checked in directed graph by
 * this topological sort method as if there is a cycle, topological sort will never exist.
 *
 * toppological sort by bfs is more useful compared to dfs.
 * to find a cycle in directed graph, after processing toppological sort bfs algo we will check as if inorder for any
 * node is not zero means there is a cycle.
 *
 * usually, if there is no cycle then after processing all nodes, inorder corresponding to each node becomes zero.
 *
 * Note: We can find out cycle in a directed graph using DFS by graph coloring mechanism also, by three states: 
 * unvisited, visited and not-completed.
 */

using namespace std;

template<typename T>
class Graph{
     map<T,list<T> > adjList;

     public:
     Graph(){ }
     void addEdge(T u, T v,bool bidir=true){
	  adjList[u].push_back(v);
	  if(bidir){
	     adjList[v].push_back(u);
	  }
     }

     void topologicalSort(){
	  queue<T> q;
	  map<T,bool> visited;
	  map<T,int> indegree;

	  for(auto i:adjList){
	      //i is pair of node and its list
	      T node = i.first;
	      visited[node] = false;
	      indegree[node] = 0;
	  }

	  //Init the indegrees of all nodes
	  for(auto i:adjList){
	      T u = i.first;
	      for(T v: adjList[u]){
		  indegree[v]++;
	      }
	  }

	  //Find out all the nodes with 0 indegree
	  for(auto i:adjList){
	      T node = i.first;
	      if(indegree[node]==0){
		 q.push(node);
	      }
	   }
	   //Start with algorithm
	   while(!q.empty()){
	      T node = q.front();
	      q.pop();
	      cout<<node<<"-->";
	      for(T neighbour:adjList[node]){
		  indegree[neighbour]--;
		  if(indegree[neighbour]==0){
		     q.push(neighbour);
		  }
	      }
	   }		
      }
};

int main(){

    Graph<string> g;
    g.addEdge("English","Programming Logic",false);
    g.addEdge("Maths","Programming Logic",false);
    g.addEdge("Programming Logic","HTML",false);
    g.addEdge("Programming Logic","Python",false);
    g.addEdge("Programming Logic","Java",false);
    g.addEdge("Programming Logic","JS",false);
    g.addEdge("Python","Web Dev",false);
    g.addEdge("HTML","CSS",false);
    g.addEdge("CSS","JS",false);
    g.addEdge("JS","Web Dev",false);
    g.addEdge("Java","Web Dev",false);
    g.addEdge("Python","Web Dev",false);

    g.topologicalSort();

    return 0;
}
