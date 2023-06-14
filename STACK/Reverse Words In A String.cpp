#include<bits/stdc++.h>

string reverseString(string &str){
	stack<string> st;

	int n=str.size();
	string ans="";
	int i=0;
	while(i<n){
		string s="";
		while(i<n && str[i]!=' ') s+=str[i],i++;
        if(s!="") st.push(s);
		i++;
	}
	while(!st.empty()){
		if(ans!="") ans+=" ";
		ans+=st.top();
		st.pop();
	}
	return ans;
}