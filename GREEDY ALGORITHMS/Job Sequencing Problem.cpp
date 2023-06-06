#include <bits/stdc++.h> 

static bool comp(vector<int> &a,vector<int> &b){
    return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    priority_queue<int,vector<int>,greater<int>> pq;
    int n=jobs.size();
    sort(jobs.begin(),jobs.end(),comp);

    int cost=0;
    int time=0;
    for(int i=0;i<n;i++){
       if(time<jobs[i][0]){
           time++;
           cost+=jobs[i][1];
           pq.push(jobs[i][1]);
       }else{
           if(!pq.empty() && pq.top()<jobs[i][1]){
               cost-=pq.top();
               pq.pop();
               pq.push(jobs[i][1]);
               cost+=jobs[i][1];
           }
       }
    }
    return  cost;
}
