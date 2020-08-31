/*************** Find number of quadrant in an array whosesum is zero *************************/
/*  If array has n elements then most trivial solution will have O(n4) time complexity using four for loops.
 *  We can solve it in O(n3) time complexity and O(n^2logn) time complexity.
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//Method - 1 [O(n3)]

#if 0
int GetNumberOfQuadrant1(vector<int> &v, int val)
{
  sort(v.begin(), v.end());    // nlogn
  int first, last, tmp, count = 0;

  for (int i = 0; i < v.size()-3; i++) {
      for (int j = i+1; j < v.size()-2; j++) {
          tmp = val - v[i] - v[j];
          first = j+1;
          last = v.size()-1;

          while (first < last) {
              if(v[first] + v[last] == tmp) {
                  cout<< v[i]<<" "<<v[j]<<" "<<v[first]<<" "<<v[last]<<endl;
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
    }

    return count;
}

#endif   

// Methhod 2 [O(n2logn)]

class int_pair
{
  public:
  int a; 
  int b;
  int sum;
  public:
  int_pair(int x, int y, int z):a(x), b(y), sum(z) {};
};

bool comparator(const int_pair& x, const int_pair& y) {
   return x.sum < y.sum;
}

bool isHavingCommonIndex(const int_pair& x, const int_pair& y) {
     return (x.a == y.a || x.a == y.b || x.b == y.a || x.b == y.b);
}

int GetNumberOfQuadrant2(vector<int> &v, int val)
{
   vector<int_pair>  v_pair;
   for (int i = 0; i < v.size()-1; i++) {        // O(n2)
       for (int j = i+1; j < v.size(); j++) {
           v_pair.push_back(int_pair(i, j, v[i]+v[j]));
       }
    }

    // sort vector
    sort(v_pair.begin(), v_pair.end(), comparator);

    int first = 0;
    int last = v_pair.size()-1;
    int count = 0;

    while(first < last) {
       if((v_pair[first].sum + v_pair[last].sum == val) && !isHavingCommonIndex(v_pair[first], v_pair[last])) {
          count++;
          first++;
          last--;
       } else if ((v_pair[first].sum + v_pair[last].sum) < val ) {
         first++;
         last--;
       } else {
         last--;
       }
    }

    return count;
}

int main()
{
   vector<int> v;
   v.push_back(10);
   v.push_back(2);
   v.push_back(3);
   v.push_back(4);
   v.push_back(5);
   v.push_back(9);
   v.push_back(7);
   v.push_back(8);
   

   //cout<<"Number of Quadrants are: "<<GetNumberOfQuadrant1(v, 23)<<endl;
   cout<<"Number of Quadrants are: "<<GetNumberOfQuadrant2(v, 23)<<endl;

   return 0;
}
