#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n) {
    // Write your code here.
    // sort(arr.begin(),arr.end());
    // int maxi=1;
    // int curr=arr[0];
    // int count=1;
    // for(int i=1;i<n;i++){
    //     if(arr[i]==curr) continue;
    //    if(arr[i]==curr+1){
    //      count++;
    //      curr=arr[i];
    //      maxi=max(maxi,count);
    //    }else{
    //        maxi=max(maxi,count);
    //        curr=arr[i];
    //        count=1;
    //    }
    // }
    // // cout<<endl;
    // return maxi;



    unordered_set<int> s;
    for(auto num:nums) s.insert(num);
    int maxi=1;

    for(auto num:nums){
        if(!s.count(num-1)){
           int curr=num;
           int len=1;

           while(s.count(curr+1)){
               len++;
               curr++;
           }
           maxi=max(maxi,len);
        }
    }
    return maxi;

}