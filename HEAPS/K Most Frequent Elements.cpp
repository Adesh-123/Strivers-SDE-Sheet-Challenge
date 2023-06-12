#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    vector<int> ans;
    priority_queue<pair<int,int>> pq;
    sort(arr.begin(),arr.end());
    int count=1;
    for(int i=1;i<n;i++){
       if(arr[i]==arr[i-1]) count++;
       else{
           pq.push({count,arr[i-1]});
           count=1;
       }

       if(i==n-1){
           pq.push({count,arr[i]});
       }
    }
    while(k--){
       auto element=pq.top().second;
       pq.pop();
       ans.push_back(element);
    }
    sort(ans.begin(),ans.end());
    return ans;
}