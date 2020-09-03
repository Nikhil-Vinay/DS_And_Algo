/*** Given two strings, print all possible interleaving strings made by these two given strings */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void GetInterleavingStrings(string string1, string string2, string res, unordered_set<string> &il_strings){
     if (string1.length() == 0){
     	res += string2;
     	il_strings.insert(res);
     	return;
     }	
     
     if (string2.length() == 0){
     	res += string1;
     	il_strings.insert(res);
     	return;
     }
     
     GetInterleavingStrings(string1.substr(1), string2, res + string1[0], il_strings);
     GetInterleavingStrings(string1, string2.substr(1), res + string2[0], il_strings);
     
}

int main()
{
	string string1 = "ABC";
	string string2 = "DEF";
	unordered_set<string> il_strings;
	GetInterleavingStrings(string1, string2, "", il_strings);
	for(string x : il_strings){
		cout<<x<<endl;
	}
	return 0;
}
