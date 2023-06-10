#include <bits/stdc++.h> 

static bool comp(pair<int,int> &a,pair<int,int> &b){
    return double((double)a.second/(double)a.first)>double((double)b.second/(double)b.first);
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.

    sort(items.begin(),items.end(),comp);
    int weight=0;
    double ans=0;
    for(int i=0;i<items.size();i++){
        // cout<<double(items[i].second/items[i].first)<<endl;
       if(weight+items[i].first>w){
        // cout<<items[i].first<<" "<<items[i].second<<endl;
           ans+=double((double)items[i].second/(double)items[i].first)*(w-weight);
           break;
       }else{
           ans+=double(items[i].second);
           weight+=items[i].first;
       }
    }
    
    return ans;
}