
/* This question has been asked in online test for ESKO on hackerearth */
/* 9 out of 10 test cases are passed */

/* There are many cities connected with each other. All cities have directed path and cost associated with it.
 * When user provides source and destination, it hould output all the paths in source to destination with below
 * constraints:
 * 1. Less cost path should come first.
 * 2. If more than one path have same cost associated then pth should come at first which has less connected path.
 *    Example: Patna Delhi 30     // direct 0 connection
 *             Patna Lucknow 30   // 1 connection
 * 3. If more than one path have same cost and same number of connected paths then it should be sorted by lexicographical order.
 *   Example: Patna Bhopal Delhi 20       'B' of Bhopal should be above than 'L' of Lucknow
 *            Patna Lucknow Delhi 20
 *            

 Input pattern:
 source  destination
 city<x> city<y> cost  
 .............
 ............
 city<x> city<z> cost
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Details
{
	public:
	string destination;
	int cost;
	Details(string indest, int incost): destination(indest), cost(incost) {}
};

class Graph
{
	public:
	int v;
	unordered_map<string, vector<Details> > edgelist;
};

class Output
{
	public:
	string str;
	int conCount;
	int totalCost;
	vector<string> cities;

	Output(int count, int cost, vector<string> cityStr, string allCityStr){
		str = allCityStr;
		conCount = count;
		totalCost = cost;
		cities = cityStr;
	}
};

vector<Output> output;

bool cmp(Output &o1, Output &o2){
	if ( o1.totalCost !=  o2.totalCost){
		return (o1.totalCost < o2.totalCost);
	}

	if (o1.conCount != o2.conCount){
		return o1.conCount < o2.conCount;
	}

	return (o1.str < o2.str);
}

void Process(Graph &graph, vector<Output> &output, unordered_set<string> &visited,
            string &src, string &dest, int cost, int count,
			vector<string> &str) {
	 if(src == dest){
		 string tmpstr = "";
		 for(int i = 0; i < str.size(); i++){
			 tmpstr += str[i];
		 }

         output.push_back(Output(count, cost, str, tmpstr));
		 return;
	 }

	 // DFS
	 vector<Details>::iterator it;
	 
	 for(it = graph.edgelist[src].begin(); it != graph.edgelist[src].end(); it++){
		 if (visited.find(it->destination) == visited.end()) {
			 visited.insert(it->destination);
			 count++;
			 cost += it->cost;
			 str.push_back(it->destination);
			 Process(graph, output, visited, it->destination, 
			        dest, cost, count, str);
			 visited.erase(visited.find(it->destination));  // backtracking
			 count--;
			 cost -= it->cost;
			 vector<string>::iterator itstr;
			 itstr = find(str.begin(), str.end(), it->destination);
			 if(itstr != str.end()) {
				 str.erase(itstr);
			 }
			 
		 }
	 }
     
}

int main() {
	string src;
	string dest;
	cin >> src >> dest;
	//cout<<src<<" "<<dest<<endl;
	Graph graph;

    while(true) {
		string tmp_src;
		string tmp_dest;
		int cost;
		cin>>tmp_src>>tmp_dest>>cost;
		if(tmp_src.length() == 0){
			break;
		}
		graph.edgelist[tmp_src].push_back(Details(tmp_dest, cost));
        //cout<<"source: "<<tmp_src<<" destination: "<<tmp_dest<<" cost: "<<cost<<endl;;
		

	}

	int count = 0, cost = 0;
    unordered_set<string> visited;
	vector<string> str;
	str.push_back( src);

	Process(graph, output, visited, src, dest, cost, count, str);

	// sort output
	sort(output.begin(), output.end(), cmp);

	// print output
	if(output.size() == 0){
		cout<<"No Trains"<<endl;
	} else {
       for(int i = 0; i < output.size(); i++){
          for(int j = 0; j != output[i].cities.size(); j++){
             cout<<output[i].cities[j]<<" ";
		  }
		  cout<<output[i].totalCost << endl;
	   }
	}

	return 0;
}


