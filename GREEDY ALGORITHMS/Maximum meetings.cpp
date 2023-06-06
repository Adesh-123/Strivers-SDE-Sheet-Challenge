#include <bits/stdc++.h> 

static bool comp(vector<int> &a,vector<int> &b){
    return a[1]==b[1]?a[2]<b[2]:a[1]<b[1];
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<vector<int>> arr;
    for(int i=0;i<start.size();i++){
        arr.push_back({start[i],end[i],i+1});
    }

    sort(arr.begin(),arr.end(),comp);

    vector<int> ans;
    int st=arr[0][0];
    int ed=arr[0][1];
    ans.push_back(arr[0][2]);

    for(int i=1;i<arr.size();i++){
        if(ed<arr[i][0]){
            st=arr[i][0];
            ed=arr[i][1];
            ans.push_back(arr[i][2]);
            
        }else if(ed>arr[i][1]){
            ans.pop_back();
            st=arr[i][0];
            ed=arr[i][1];
            ans.push_back(arr[i][2]);
        }
        // cout<<st<<" "<<ed<<endl;
    }
    return ans;
}