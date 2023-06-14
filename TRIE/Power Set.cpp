#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    sort(v.begin(),v.end());
    vector<vector<int>> ans;
    int n=v.size();
    int size=pow(2,n);
    int i=0;
    while(i<size){
        vector<int> a;
        for(int j=0;j<n;j++){
            if((i&(1<<j))!=0){
               a.push_back(v[j]);
            }
        }
        i++;
        ans.push_back(a);
    }
    return ans;
}