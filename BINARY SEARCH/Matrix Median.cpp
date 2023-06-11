#include<bits/stdc++.h>

int possible(int mid,vector<vector<int>> &matrix){
    int count=0;
    int m=matrix.size();
    int n=matrix[0].size();
    for(int i=0;i<m;i++){
      auto index=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
      count+=(n-index);
    }
    return count;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int mini=INT_MAX;
    int maxi=INT_MIN;
    int m=matrix.size();
    int n=matrix[0].size(); 

    for(int i=0;i<m;i++){
        mini=min(mini,matrix[i][0]);
        maxi=max(maxi,matrix[i][n-1]);
    }

    int low=mini;
    int high=maxi;
    while(low<=high){
        int mid=(low+high)/2;

        if(possible(mid,matrix)>(m*n)/2){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}