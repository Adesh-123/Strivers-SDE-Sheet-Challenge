#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	
	public:
		
		stack<pair<int,int>> st;
		int mini=INT_MAX;
		minStack() 
		{ 
			
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			if(st.empty()) st.push({num,num});
			else st.push({num,min(num,st.top().second)});
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(st.empty()) return -1;
			int val=st.top().first;
			st.pop();
			return val;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(st.empty()) return -1;
			return st.top().first;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(st.empty()) return -1;
			return st.top().second;
		}
};