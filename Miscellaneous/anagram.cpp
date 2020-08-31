/********** FInd if two strings are anagrams **********************/

#include<iostream>
#include<bits/stdc++.h>
#define DEBUG 1

using namespace std;

/* Method - 1 
 * The problem of this method is space complexity and time complexity. Here we are considering string will
 * have only small letters then space complexity is O(26) and time complexity is also O(26). Suppose string
 * will have all upper, lower case and special characters then? Suppose string will have unicode characters
 * in future then? Method-2 is appropriate solution for this.*/

bool IsAnagram(string str1, string str2)
{
  if(str1.length() != str2.length()) {
    return false;
  }
  char arr[26]; // considering all small letters
  memset(arr, 0, sizeof(arr));
  for(int i = 0; i < str1.length(); i++) {
    int index = str1[i]-'a';
    cout<<index<<endl;
    arr[index]++;
  }

  // check for str2
  for(int i = 0; i < str2.length(); i++) {
     int index = str2[i]-'a';
     arr[index]--;
  }

  // check for anagram
  for(int i = 0; i < 26; i++) {
    if(arr[i] > 0){
       return false;
    }
  }
  
  return true;
}

/* Method - 2.
 * We use self balancing binary tree to solve this problem. We are using set for self balancing binary tree 
 * Space complexity - O(n)    // n is string length
 * Time Complexity - O(nlogn)
 */

class CharDet
{
   public:
   char ch;
   int count;
   CharDet(char in_ch, int in_count):ch(in_ch),count(in_count){}; 
};

class CustomComp
{
  public:
  bool operator()(const CharDet &obj1, const CharDet &obj2){
     return (obj1.ch) < (obj2.ch);
  }

  // Note this comparator can have more than onne () operotor method definition means overloaded () operator
  // method
};

bool IsAnagram2(string str1, string str2)
{
  if(str1.length() != str2.length()) {
     return false;
  }

  set<CharDet, CustomComp> myset;
  set<CharDet, CustomComp>::iterator it;

  for(int i = 0; i < str1.length(); i++) {
    it = myset.find(CharDet(str1[i], 0)); //it searches with help of comparater and matches only ch so count
                                          // could be dummy
                                          // iterator will move as inorder traversal
    if(it != myset.end()) {
      //it->count++;  // can't do this. count becomes read only so we need to do a new insert
      int count = it->count;
      myset.erase(it);                         // O(logn)
      myset.insert(CharDet(str1[i], ++count)); // O(logn)
    } else {   
      myset.insert(CharDet(str1[i], 1));       
    }
  }

  for(int i = 0; i < str2.length(); i++) {
     it = myset.find(CharDet(str1[i], 0));
     if(it == myset.end()){
        return false;
     } else {
       int count = it->count;
       myset.erase(it);                            // O(n)
       if(count > 1) {
          myset.insert(CharDet(str1[i], --count)); // O(n)
       }
    }
  }

  if(myset.size() == 0) {
    return true;
  } else {
    return false;
  }
  
}

int main()
{
  string str1("abcd");
  string str2("dcba");
  //cout<<(IsAnagram(str1, str2)?"Anagram":"Not Anagram")<<endl;
  cout<<(IsAnagram2(str1, str2)?"Anagram":"Not Anagram")<<endl;
  return 0;
}
