/*************** Find number of triplet in an array whosesum is zero *************************/
/*  If array has n elements then most trivial solution will have O(n3) time complexity using three for loops.
 *  We can solve it in O(n2) time complexity.
 *
 *  Addition to below solution: If question says, don't make any element common in more than one triplet.
 *  We will have an additional array of n boolean val. once we find any triplet in the loop, triplet indexes
 *  are set to true in boolean array and further while checking for triplets, we need to check if perticular
 *  index val is already used or not.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int GetNumberOfTriplet(vector<int> &v, int val)
{
   int count = 0;
   int first, last, tmp; 
   // sort vector
   sort(v.begin(), v.end());   // nlogn
 
   for(int i = 0; i < v.size()-2; i++) {  // n2
      first = i+1;
      last = v.size()-1;
      tmp = val - v[i]; 
      while(first < last) {
        if(v[first] + v[last] == tmp) {
           count++;
           first++;
           last--;
        } else if (v[first] + v[last] < tmp) {
          first++;
        } else if (v[first] + v[last] > tmp) {
          last--;
        }
      }
   }

    // time complexity = O(nlogn + n2) ~ O(n2)
   return count;
}

int main()
{
   vector<int> v;
   v.push_back(0);   
   v.push_back(-1);   
   v.push_back(2);   
   v.push_back(-3);   
   v.push_back(1);   

   cout<<"Number of Triplets are: "<<GetNumberOfTriplet(v, 0)<<endl;

   return 0;
}
