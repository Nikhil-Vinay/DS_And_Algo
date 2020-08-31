/*********** Build Itinerary ****************************/
/* Given a list of tickets, find itinerary in order using the given list.
 *
 * Example:
 *
 * Input:
 * "Chennai" -> "Banglore"
 * "Bombay" -> "Delhi"
 * "Goa"    -> "Chennai"
 * "Delhi"  -> "Goa"
 *
 * Output: 
 * Bombay->Delhi, Delhi->Goa, Goa->Chennai, Chennai->Banglore,
 * It may be assumed that the input list of tickets is not cyclic and there is one ticket from every city except
 * final destination.
 *
 * One Solution is to build a graph and do Topological Sorting of the graph. Time complexity of this solution is
 * O(n).
 *
 * We can also use hashing to avoid building a graph. The idea is to first find the starting point. A starting 
 * point would never be on ‘to’ side of a ticket. Once we find the starting point, we can simply traverse the 
 * given map to print itinerary in order. Following are steps.
 *
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void PrintItinerary(map<string, string> &src_dest)
{
   // since there is no cycle so destination will never be as a key in src_dest map
   // create a map as dest to source where source will never be as a key

   map<string, string> dest_src;

   map<string, string>::iterator it;

   for(it = src_dest.begin(); it != src_dest.end(); it++) {
      dest_src[it->second] = it->first;
   }

   string src(""), dest("");
   // find source in dest_src map
   for(it = src_dest.begin(); it != src_dest.end(); it++) {
      if(dest_src.find(it->first) == dest_src.end()) {
         src = it->first;
         break;
      }
   }

   // find dest in src_dest map
   for(it = dest_src.begin(); it != dest_src.end(); it++) {
      if(src_dest.find(it->first) == src_dest.end()) {
         dest = it->first;
         break;
      }
    }

    if(src.length() == 0 || dest.length() == 0) {
      cout<<"Invalid Inputs"<<endl;
    }

    // print itinerary
    it = src_dest.find(src);
    while(it != src_dest.end()){
       cout<<it->first<<" -> "<<it->second<<endl;
       it = src_dest.find(it->second);
    }
}

int main()
{
  map<string, string> src_dest;
  src_dest["Chennai"] = "Bangalore";
  src_dest["Bombay"] = "Delhi";
  src_dest["Goa"] = "Chennai";
  src_dest["Delhi"] = "Goa";

  PrintItinerary(src_dest);
  return 0;
}
