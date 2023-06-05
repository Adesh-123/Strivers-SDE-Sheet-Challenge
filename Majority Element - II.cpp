#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    map<int,int> m;
    for(int i=0;i<arr.size();i++){
        m[arr[i]]++;
    }
    int count=arr.size()/3;
    vector<int> ans;
    for(auto curr:m){
        if(curr.second>count) ans.push_back(curr.first);
    }
    return ans;
}