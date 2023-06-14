#include <bits/stdc++.h> 

void solver(stack<int> &st,int val){
	if(st.empty()){
		st.push(val);
		return;
	}

	int val1=st.top();
	if(val1>val){
		st.pop();
		solver(st,val);
		st.push(val1);
	}else{
		st.push(val);
	}
}

void sortStack(stack<int> &st)
{
	if(st.empty()) return;

	int val=st.top();
	st.pop();
	sortStack(st);
	solver(st,val);
}