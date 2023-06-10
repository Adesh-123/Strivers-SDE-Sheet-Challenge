#include <bits/stdc++.h> 

void solver(int i,int n,vector<int> &arr,vector<int> &ans,set<vector<int>> &s){   

     if(i==n){
        s.insert(ans);
         return ;
     }

     solver(i+1,n,arr,ans,s);
     ans.push_back(arr[i]);
     solver(i+1,n,arr,ans,s);
     ans.pop_back();
}


vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{   sort(arr.begin(),arr.end());
    set<vector<int>> s;
    vector<int> ans;
    solver(0,n,arr,ans,s);
    vector<vector<int>> a;
    for(auto x:s){
        a.push_back(x);
    }
    return a;
}