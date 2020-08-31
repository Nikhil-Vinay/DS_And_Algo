/***************************  Find if expression is balanced ******************************/
/* Given a string of round, curly and square open and closing brackets, return whether the brackets are balanced
 * (well - formed).
 *
 * Ex: string - "([])[]({}0)"    // return true
 *     string - "([)]"           // return false
 *
 * It is a beautiful example of problem based on stack */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool IsStrBalanced(string str)
{
  stack<char> st;
  for(int i = 0; i < str.length(); i++) {
    if(st.empty()) {
       st.push(str[i]);
    } else {
      char c = str[i];
      if((c == '(') || (c == '{') || (c == '[')){
        st.push(c);
      } else if((c == ')') || (c == '}') || (c == ']')){
        switch(c) {
           case ')':
                     if(st.top() == '(') {
                        st.pop();
                     }
                     break;
           case '}':
                     if(st.top() == '{') {
                        st.pop();
                     }
                     break;
           case ']':
                     if(st.top() == '[') {
                        st.pop();
                     }
                     break;
        }
      }
    }
  }

  return (st.empty()?true:false);
}

int main()
{
   //string str("([])[]({}0)");
   string str("([)]");
   cout<<(IsStrBalanced(str)?"true":"false")<<endl;

   return 0;
}
