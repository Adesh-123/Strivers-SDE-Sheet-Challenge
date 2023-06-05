#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  map<int,int>m;
  m[0]=-1;
  int sum=0;
  int maxilen=0;
  for(int i=0;i<arr.size();i++){
     sum+=arr[i];
     if(m.find(sum)!=m.end()){
        maxilen=max(maxilen,i-m[sum]);
     }else m[sum]=i;
  }
  return maxilen;
}