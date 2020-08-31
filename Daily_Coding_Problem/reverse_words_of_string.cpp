/* Given a string of words delimited by spaces, reverse the words in string. For example, given "hello world here", return "here world hello" */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void ReverseString(string &str, int start, int end)
{
   while(start < end) {
     str[start] = str[start]^str[end];
     str[end] = str[start]^str[end];
     str[start] = str[start]^str[end];
     start++;
     end--;
   }
}

void ReverseWordsOfString(string &str) {
     // reverse All Words one by one
     int start = 0;
     int end = 0;

     while (end <= str.length()) {
        if (str[end] == ' ' || end == str.length()) {
           ReverseString(str, start, end-1);
           if(str[end] == ' ') {
              start = end+1;
              end = start;
           } else if (end == str.length()) {
             break;
           }
        } else {
           end++;
        }
     }

    // Reverse Whole String
    ReverseString(str, 0, str.length()-1);
}

int main()
{
   string str = "hello world here";
   ReverseWordsOfString(str);
   cout<<str<<endl;
   return 0;
}
   
