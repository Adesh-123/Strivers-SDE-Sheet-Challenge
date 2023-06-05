#include <bits/stdc++.h>


bool twosum(int low,int high,int target,vector<int> arr){
     map<int,int>m;
     for(int i=low;i<=high;i++){
         if(m.find(target-arr[i])!=m.end()) return true;
         m[arr[i]]++;
     }
     return false;
}

string fourSum(vector<int> nums, int target, int n) {
    // Write your code here.

    sort(nums.begin(),nums.end());
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            int k=j+1;
            int z=n-1;
            while(k<z){
                int sum=nums[i]+nums[j]+nums[k]+nums[z];
                if(sum==target) return "Yes";
                else if(sum>target) z--;
                else k++;
            }
        }
    }
    return "No";
}
