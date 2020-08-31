/* Prob: There is an integer array of n element, you need to find an index i so left subarray(0-i) and
   right subarray(i+1 - n-1) have same value(by adding all elements).
   If you are at index then you can take one element from left subarray and insert into right subarray and 
   similarly you can take one element from right subarray and insert into left subarray.
   Ex: 2 2 3 6 1  // if i = 1, left subarray(2+2 = 4), right subarray(3+6+1 = 10), remove 3 from right subarray a                     insert to left subarray
       6 6 3 2 1  // if i = 0, left subarray(6), right subarray(6+3+2+1=12), If we take one 3 from right
                    subarray and insert into left subarray then left subarray(6+3 = 9), right subarray(6+2+1=9).

*/

// TIme complexity os below solution is O(NlogN), because we are traversing with all N elements and if each 
//  element will have an update then each update will have time complexity in O(logN).
//  Normal map is internally self balanced binary search tree so each update will take O(logN).
//  Instead of update, we can go with insert and delete with same time complexity but update is better.

// We can reduce the time complecxity little if we'll use unordered_map (supported by c++11). 
// Unordered_map has hashing mechanism internally to update/insert/delete so time complecxity is o(1).
// SO, this program solutions time complexity will become O(N) instead of o(NlogN) by using unorderd_map.

#include<iostream>
#include<map>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  map<int, int> left_map;
  map<int, int> right_map;
 
  for(int i = 0; i < n; i++) {
    left_map[arr[i]] = 0;
    right_map[arr[i]] = 0;
  }

  int sum = 0;
  for(int i = 0; i < n; i++) {
     if( i == 0) {
       left_map[arr[i]]++;
     }
     else {
       right_map[arr[i]]++;
     }
     sum += arr[i];
  }

  int leftsum = arr[0];
  bool found = false;
  for(int i = 0; i < n-1; i++) {
     if(leftsum == (sum/2)) {
        cout<<" found the index "<<i<<endl;
        found = true;
        break;
     } else if(leftsum < (sum/2)) {
       if(right_map[(sum/2) - leftsum]) {
          cout << " found the index "<<i<<" by removing one element "<<(sum/2 - leftsum)<<" from right subarray and insert to left subarray"<<endl;
          found = true;
          break;
       }
     } else if(leftsum > (sum/2)) {
        if(left_map[(sum/2) - leftsum]) {
           cout << " found the index "<<i<<" by removing one element "<<(sum/2 - leftsum)<<" from left subarray and insert to right subarray"<<endl;
           found = true;
           break;
        }
     }

       left_map[arr[i]]++;
       right_map[arr[i]]--;
       leftsum += arr[i];       
   
  }

  if(found == false) {
    cout << "Didn't get any solution"<<endl;
  }

  return 0;
}
