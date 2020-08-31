/* There is ground which has N number of gardens connected to each other. We have four color of flowers [1, 2, 3,4].
 * Print the folower color of each garden so that two adjascent garden wont have the same color.
 * Note: Any garden can have maximum 3 connections.
 *
 * Solutions: Constraint ofthis problem is key of the solution. We have four distinct color of flowers and any
 * garden cant have more than 3 connection with other gardens.
 *
 * No need to visit in DFS and do backtracking.
 * This problem has been taken from leetcode.
 */
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void GetFlowerColors(vector<pair<int, int> > &g, int n, vector<int> &res)
{
   map<int, vector<int> > graph;
   vector<pair<int, int> >::iterator it;
   for(it = g.begin(); it != g.end(); it++){
       graph[it->first-1].push_back(it->second-1);
       graph[it->second-1].push_back(it->first-1);
   }

   res.resize(n);
   for(int i = 0; i < n; i++){
      res[i] = 0;
   }

   int used = 0;

   vector<int>::iterator it1;
   for(int i = 0; i < n; i++) {
      for(it1 = graph[i].begin(); it1 != graph[i].end(); it1++) {
         used |= (1 << res[*it1]);
      }
      // assign a color to garden i
      for(int j = 1; j <= 4; j++) {
         if((used & (1<<j)) == 0){
            res[i] = j;
//            cout<<"assigning at "<<i<<" "<<j<<endl;
            break;
         }
      }
   }
}

int main()
{
   int n, c;
   cout<<"Enter number of gardens: "<<endl;
   cin >> n;
   cout<<"Enter number of connections: "<<endl;
   cin>>c;
   vector<pair<int, int> > g;
   cout<<"Enter the connections in pair:"<<endl;
   for(int i = 0; i <c; i++) {
      int x, y;
      cin>>x>>y;
      g.push_back(make_pair(x,y));
   }

   vector<int> res;
   //res.reserve(n);
   GetFlowerColors(g, n, res);
   cout<<"Flower colors at garden: "<<endl;
   for(int i = 0; i < res.size(); i++) {
      cout<<res[i]<<" ";
   }
   cout<<endl;
   return 0;
}
