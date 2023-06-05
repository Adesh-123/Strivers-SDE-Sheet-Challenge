#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.

    int n=prices.size();
    int maxi=prices[n-1];
    int ans=0;
    for(int i=n-2;i>=0;i--){
        ans=max(ans,maxi-prices[i]);
        maxi=max(maxi,prices[i]);
    }
    return ans;
}