/* There is a river whose one bank is northern bank and other is southern bank. There is set of pair of points
 * . Each pair of points contain one point at northern side and one point at southern side. We need to find
 * out hown many bridges can be build so that no bridge would cross to each other.
 *
 * Note: if pair1 consists x and y then x can be connected with y only. It means one point from pair1 can't be
 * connected with any point from other pair, points from same pair can be connected only.
 */


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct point_s
{
   int s;
   int n;
}point;

struct my_cmp
{
   // sort in ascending order
   bool operator() (const point &p1, const point &p2) {
       return p1.s < p2.s;
   }
};

bool comp(int a, int b) 
{ 
    return (a < b); 
}

int MaxBridgeCount(vector<point> &vct)
{
   // Our goal is to find maximum number of bridges with combination of southern-northen given pair of points.
   // So that there should not be any overlapping of bridges.
   // All points are in linear co-ordinates.
   // Sort the vector with help of any of southern or northern co-ordinates. I am sorting here based on southern
   // co-ordinates. Here all pairs will get sorted by southern co-ordinates.
   // Now, one side of the river points are sorted in linear co-ordinates, so our job is to find the max number
   // of points grab from opposite side of the river in sorted order so no overlapping will happen.
   // Its clear, we have to find longest increasing subsequence in northern points. Its done now.

   //sort(vct.begin(), vct.end(), [](const point& p1, const point& p2)->bool { return p1.s < p2.s; });
   sort(vct.begin(), vct.end(), my_cmp());

   // Find longest increasing subsequence for northern points;
   int i = 0, j = 0, lcs = 1;
   size_t n = vct.size();
   vector<int> dp;
   dp.resize(n);
   for(int i = 0; i < n; i++) {  // initialize dp table with base condition, each letter has 1 LCS.
      dp[i] = 1;
   }

   i = 1;
   while (i < n) {
      for(j = 0; j < i; j++) {
         if(vct[j].n > vct[i].n) {
           if(dp[j]+1 > dp [i]) {
              dp[i] = dp[j] + 1;
           }
         }
      }
      i++;
   }

   // Note: std::max(a, b) // used to get max out of two numbers only
   // max_element is used to get max element out of an array or vector
   // lcs = *max_element(dp, dp+n) // if dp was an array
   lcs = *max_element(dp.begin(), dp.end()); 
   return lcs;
}

int main()
{
   int n, i;
   cout<<"Enter the number of pairs of southern and northern points"<<endl;
   cin>>n;
 
   vector<point> vct;
   vct.resize(n);
   cout<<"Enter the southern co-ordinates of all points"<<endl;
   for(i = 0; i < n; i++) {
      cin >> vct[i].s;
   }

   cout<<"Enter the northern co-ordinates of all points"<<endl;
   for(i = 0; i < n; i++) {
      cin >> vct[i].n;
   }

   cout<<"Max number of bridge possible is: "<<MaxBridgeCount(vct)<<endl;
      
   return 0;
}
