#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
   stack<int> st;
   for(int i=n-1;i>=0;i--){
       while(!st.empty() && arr[i]>=st.top()){
           st.pop();
       }
       int val=arr[i];
       if(st.empty()) arr[i]=-1;
       else arr[i]=st.top();
       st.push(val);
   }
   
   return arr;
}