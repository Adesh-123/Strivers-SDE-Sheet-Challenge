#include<bits/stdc++.h>
static bool comp(vector<int> &a,vector<int> &b){
    return a[0]==b[0]?a[1]<b[1]:a[0]<b[0];
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<vector<int>> arr;
    for(int i=0;i<start.size();i++){
        arr.push_back({start[i],finish[i]});
    }

    sort(arr.begin(),arr.end(),comp);
    int st=arr[0][0];
    int ed=arr[0][1];
    int count=1; 

    for(int i=1;i<start.size();i++){
       if(ed>arr[i][1]){
           st=arr[i][0];
           ed=arr[i][1];
       }else if(ed<=arr[i][0]){
           st=arr[i][0];
           ed=arr[i][1];
           count++;
       }
    }
    return count;
}