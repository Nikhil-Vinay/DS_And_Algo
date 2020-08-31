/* Given a string and a set of delimiters, reverse the words in the string while maintaining the relative order 
 * of the delimiters. For example, given "hello/world:here", return "here/world:hello"
 *
 * Follow-up: Does your solution work for the following cases: "hello/world:here/", "hello//world:here"
 */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void ReverseStringWords(string &str)
{
   stack<string> s_stack;   // string stack, word order reverse
   queue<string> d_queue;   // delimeter queue, delimeter order won't reverse
   string tmp_s_str("");
   string tmp_d_str("");
   int len = str.length();
   int i = 0;
   char cur_ch, last_ch;
   while(i < len) {
      if((str[i] != ':') && (str[i] != '/')) {
        tmp_s_str += str[i];
        cur_ch = 's';    
      } else {
        tmp_d_str += str[i];
        cur_ch = 'd'; 
      }
      if( i == 0) {
        last_ch = cur_ch;
      }

      if(last_ch != cur_ch) {
        if(cur_ch == 'd') {
           s_stack.push(tmp_s_str);
           tmp_s_str = "";
        } else if(cur_ch == 's') {   
           d_queue.push(tmp_d_str);
           tmp_d_str = ""; 
        }              
      }

      last_ch = cur_ch;
      i++;
   }
 
   if(tmp_s_str.length() != 0) {
     s_stack.push(tmp_s_str);
   }
   if(tmp_d_str.length() != 0) {
     d_queue.push(tmp_d_str);
   }

   // Form the string
   str = "";   // clear the input string
   char cur = 's';
   while(!s_stack.empty() || !d_queue.empty()) {
       if(cur == 's' && !s_stack.empty()) {
         str += s_stack.top();
         s_stack.pop();
         cur = 'd';
       }
      if(cur == 'd' && !d_queue.empty()) {
        str += d_queue.front();
        d_queue.pop();
        cur = 's';
      }
   }
}

int main()
{
   //string str = "hello/world:here";
   //string str = "hello/world:here/";
   string str = "hello//world:here";
   ReverseStringWords(str);
   cout<<str<<endl;
   return 0;
}
