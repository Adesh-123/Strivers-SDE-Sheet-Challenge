#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
         vector<vector<long long>> ans;
         vector<long long> prev;
         prev.push_back(1);
         ans.push_back(prev);
         if(n==1) return ans; 
         prev.push_back(1);
         ans.push_back(prev);
         if(n==2) return ans;
         int i=3;
         int j=0;
         while(i<=n){
             j=0;
             vector<long long> arr;
             arr.push_back(1);
             for(int j=0;j<prev.size()-1;j++){
                 arr.push_back(prev[j]+prev[j+1]);
             }             
             arr.push_back(1);
             prev=arr;
             ans.push_back(arr);
             i++;
         }
        return ans;
}
