/** MST stands for minimum spanning tree ***/
/* MST is calculated for undirected weighted and connected graph only **/
/* Number of MST edges  = total number of vertices -1 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class edge
{
   public:
   int u;
   int v;
   int wt; 
   edge(int _u,int _v, int _wt):u(_u), v(_v), wt(_wt) {}
};

int GetParent(int *parent, int u)
{
   if (parent[u] == u) {
      return u;
   }
   GetParent(parent, parent[u]);
}

bool cmp(const edge &edge1, const edge &edge2)
{
  return edge1.wt < edge2.wt;
}
 
void krushkal(vector<edge> &graph, vector<edge> &output, int n)
{
   // sort edges with help of weight
   sort(graph.begin(), graph.end(), cmp);
 
   // create parent array, all nodes will be parent of self in beginning
   int* parent = new int[n];
   for(int i = 0; i < n; i++) {
       parent[i] = i;
   }

   int cnt = 0;
   int i = 0;
   while(cnt < n-1) {   // pick n-1 edges
      int u = graph[i].u;
      int v = graph[i].v;

      int p1 = GetParent(parent, u);
      int p2 = GetParent(parent, v);

      if(p1 == p2) {
      } else {
         output.push_back(graph[i]);
         parent[p1] = parent[p2];
         cnt++;
      }
      i++; 
   }
}

int main()
{
   int n, e;
   cout<<"Enter number of vertices:"<<endl;
   cin>>n;
   cout<<"Enter number of edges:"<<endl;
   cin>>e;

   vector<edge> graph;
   vector<edge> output;

   int i = 0;
   int u, v, wt;
   cout<<"Enter edge as u v wt"<<endl;
   while(i < e) {
     cout<<"Enter edge number: "<<i+1<<endl;
     cin>>u>>v>>wt;
     graph.push_back(edge(u, v, wt));
     i++;
  }

  krushkal(graph, output, n);

  cout<<"MST edges are: "<<endl;
  for(int i = 0; i < output.size(); i++) {
     cout<<output[i].u<<"---"<<output[i].v<<"---"<<output[i].wt<<endl;
  }

}
