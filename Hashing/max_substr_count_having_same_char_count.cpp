/* Given a string and character with count. Find out number of subctring of the string which has exact count of
 * given character */
/* Example: string is: "aabcebfgbe" and given character is 'b' and character count is 2
 * Answer is: 15
 * Strings are:"aabceb", "aabcebf","aabcebfg", "abceb", "abcebf", "abcebfg", "bceb", "bcebf", "bcebfg",
 *             "cebfgb", "cebfgbe", "ebfgb", "ebfgbe", "bfgb", "bfgbe"
 */            

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int MaxSubstrCount(string& str, char& ch, int& cnt)
{
   // Find out indexes of the character in string and store in an array;
   vector<int> vct;
   vct.push_back(-1);   // first element (one less of first index)
   for(int i = 0; i < str.length(); i++) {
      if(str[i] == ch) {
        vct.push_back(i);
      }
   }
   vct.push_back(str.length());  // last element (onde more of last index)

   // if number of given character in string is less than given count then number of substring is 0
   if(vct.size()-2 < cnt) {
     return 0;
   }
   cout<<"size: "<<vct.size()<<endl;

   // It is seen in Coding block code Kaze webinar.

   // traverse in the vector, extract set continuous character indexes stored in array which has given count
   // Example: string = aabcebfgbe, char = b, count = 2
   // vector will be: 0,2,5,8,10  // 0 is first elemet default and 10 is last element (strlen) default
   // here two subsets of count 2 are: {2,5} and {5,8}
   // substring with each set = number of character before first element of set * number of character post last 
   // element of subset before new occurence of char found
   // number of substring with subset {2,5} = ((2 - (-1)) * ((8-5)) = 3 * 3 = 9 
   // number of substring with subset {5,8} = (8-5) * (10-8) = 3 * 2 = 6      
   int index1 = 0;
   int index2 = 0;
   int index3 = 0;
   int index4 = 0;
   int count = 0;
   for(int i = 1; i < vct.size()-cnt; i = i++) {
       index1 = i-1;
       index2 = i;
       index3 = i+cnt-1;
       index4 = index3+1;
       //cout<<"One: "<<one<<" teo: "<<two<<" three: "<<three<<" four: "<<four<<endl;
       count += (vct[index2] - vct[index1]) * (vct[index4] - vct[index3]);
 
   }
 
   return count;
}

int main()
{
   string str;
   char ch;
   int cnt;
   cout<<"Enter the string: "<<endl;
   getline(cin, str);
   cout<<"Enter the character and the count: "<<endl;
   cin>>ch>>cnt;
   cout<<"Number of substrings are: "<<MaxSubstrCount(str, ch, cnt)<<endl;
   return 0;
}  
