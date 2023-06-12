#include <bits/stdc++.h> 

vector<int> merging(vector<int> a,vector<int> b){
    vector<int> nums;
    int n1=a.size();
    int n2=b.size();
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(a[i]>=b[j]) nums.push_back(b[j]),j++;
        else nums.push_back(a[i]),i++;
    }

    while(i<n1) nums.push_back(a[i]),i++;
    while(j<n2) nums.push_back(b[j]),j++;
    return nums;
}

vector<int> solver(int i,vector<vector<int>> &kArrays,int k){
    if(i==k-1) return kArrays[i];

    vector<int> a=solver(i+1,kArrays,k);

    vector<int> b=merging(kArrays[i],a);

    return b;
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    return solver(0,kArrays,k);
}
