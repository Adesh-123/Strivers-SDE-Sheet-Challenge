#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.

    vector<long> prefix(n);
    prefix[0]=arr[0];
    for(int i=1;i<n;i++){
        prefix[i]=max(prefix[i-1],arr[i]);
    }
    vector<long> suffix(n);
    suffix[n-1]=arr[n-1];
    for(int j=n-2;j>=0;j--){
        suffix[j]=max(suffix[j+1],arr[j]);
    }
    long ans=0;
    for(int i=0;i<n;i++){
        ans=ans+(min(suffix[i],prefix[i])-arr[i]);
    }
    return ans;
}