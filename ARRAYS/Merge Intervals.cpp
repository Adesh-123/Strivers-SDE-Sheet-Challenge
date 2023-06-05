#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

bool comp(vector<int> &a,vector<int> &b){
    return a[0]==b[0]?a[1]<b[1]:a[0]<b[0];
}

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    int n=intervals.size();
    sort(intervals.begin(),intervals.end(),comp);

    int start=intervals[0][0];
    int end=intervals[0][1];

    vector<vector<int>> ans;
    if(n==1){
        ans.push_back({start,end});
        return ans;
    }


    for(int i=1;i<n;i++){
       if(intervals[i][0]>end){
           ans.push_back({start,end});
           start=intervals[i][0];
           end=intervals[i][1];
       }else if(intervals[i][0]<=end){
           end=max(intervals[i][1],end);
       }

       if(i==n-1){
           ans.push_back({start,end});
       }
    }
    return ans;
}
