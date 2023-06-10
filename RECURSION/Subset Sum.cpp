#include <bits/stdc++.h> 

vector<int> ans;

void solver(int i,vector<int> &nums,vector<int> &a){
    if(i==nums.size()){
        int sum=0;
        for(int j=0;j<a.size();j++) sum+=a[j];
        ans.push_back(sum);
        return;
    }
    
    solver(i+1,nums,a);
    
    a.push_back(nums[i]);
    solver(i+1,nums,a);
    a.pop_back();
}

vector<int> subsetSum(vector<int> &num)
{    
     ans.clear(); 
     vector<int> a;
     solver(0,num,a);   
     sort(ans.begin(),ans.end());
     return ans;
}