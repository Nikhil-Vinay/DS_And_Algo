#include<iostream> 
#include<stdlib.h>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

int memo[64][100] = {-1}; // restricting to 2^6 = 64 person and 100 tshirts

int FindNumWaysToWearTShirt(vector<vector<int> > &vct, int person_count, int person_mask, int tshirtcount, int tshirtid)
{
  cout<<"Mask is--"<<person_mask<<endl;
  if(person_mask == ((1<<person_count)-1))
  {
     cout<< "yes is "<<endl;
     return 1;
  }

  if(tshirtid >= tshirtcount)
     return 0;

  if(memo[person_mask][tshirtid] != -1)
     return memo[person_mask][tshirtid];

  // exclude tshirt, we wont give this tshirt to anyone
  int ans = FindNumWaysToWearTShirt(vct, person_count, person_mask, tshirtcount, tshirtid+1);

  vector<int> localvct;

  localvct = vct[tshirtid];
  for(vector<int>::iterator it = localvct.begin(); it != localvct.end(); it++)
  {
      if(!(person_mask & (1<<(*it))))
      {
        cout<<"Tshirt id --"<<tshirtid<<"--tshirt count--"<<tshirtcount<<"--person id--"<<*it<<endl;
//        person_mask |= (1<<(*it));
        ans += FindNumWaysToWearTShirt(vct, person_count, (person_mask | (1<<(*it))), tshirtcount, tshirtid+1);
      }
  }

  memo[person_mask][tshirtid] = ans;
  return ans;
}

void PrintMapping(vector<vector<int> > &vct)
{
  vector<vector<int> >::iterator it;
  int tshirtid = 0;
  for(it = vct.begin(); it != vct.end(); it++)
  {
    cout<<tshirtid<< " -> ";
    vector<int>::iterator innerit;
    for(innerit = it->begin(); innerit != it->end(); innerit++)
    {
      cout<<*innerit<<" ";
    }
    cout<<endl;
    tshirtid++;
  }
  cout<<endl;
}

int main()
{
  vector<vector<int> > vct;
  int n;
  cout<<"Enter the number of tshirts: "<<endl;
  cin >> n;
  vector<int> tmpvct;
  for(int i = 0; i < n; i++)
  {
    tmpvct.clear();
    tmpvct.push_back(0);
    tmpvct.push_back(1);

    vct.push_back(tmpvct);
    
  }
  PrintMapping(vct);
  cout<< "Number of ways: "<<FindNumWaysToWearTShirt(vct, 2, 0, n, 0)<<endl;
  return 0;
}
