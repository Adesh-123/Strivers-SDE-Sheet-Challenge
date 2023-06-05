#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    map<int,int>m;
    int xors=0;
    int count=0;
    m[0]=1;
    for(int i=0;i<arr.size();i++){
      xors^=arr[i];
      if(m.find((xors^x))!=m.end()){
         count+=m[xors^x];
      }
      m[xors]++;
    }
    return count;
}