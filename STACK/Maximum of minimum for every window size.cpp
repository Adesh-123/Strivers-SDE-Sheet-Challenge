#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> prefix(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]>=a[i]) st.pop();
        if(st.empty()) prefix[i]=-1;
        else prefix[i]=st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    vector<int> suffix(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[st.top()]>=a[i]) st.pop();
        if(st.empty()) suffix[i]=n;
        else suffix[i]=st.top();
        st.push(i);
    }

    vector<int> minlength(n,INT_MIN);
    for(int i=0;i<n;i++){
        minlength[suffix[i]-prefix[i]-2]=max(minlength[suffix[i]-prefix[i]-2],a[i]);
    }

    for(int i=n-2;i>=1;i--){
        minlength[i]=max(minlength[i+1],minlength[i]);
    }
    return minlength;
}