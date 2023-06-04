#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &nums, int n)
{
    //  Write your code here.
            if(nums.size()==1) return nums;
        int i;
        for(i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]) break;
        }
        if(i!=-1){
              for(int j=nums.size()-1;j>i;j--){
               if(nums[j]>nums[i]){
                   swap(nums[j],nums[i]);
                   break;
               }
            }
        }

        reverse(nums.begin()+i+1,nums.end());
        return nums;
}