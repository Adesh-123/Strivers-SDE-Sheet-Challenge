#include <bits/stdc++.h>

bool comp(vector<int> a,vector<int> b){
   return a[0]==b[0]?a[1]<b[1]:a[0]<b[0];
}

vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> ans;

   map<int,int>m;
   for(int i=0;i<arr.size();i++){
      if(m.find(s-arr[i])!=m.end()){
         vector<int> a;
         a.push_back(arr[i]);
         a.push_back(s-arr[i]);
         sort(a.begin(),a.end());
         int c=m[s-arr[i]];
         while(c--) ans.push_back(a);
         m[arr[i]]++;
      }
      else m[arr[i]]++;
   }
   sort(ans.begin(),ans.end(),comp);
   return ans;
}