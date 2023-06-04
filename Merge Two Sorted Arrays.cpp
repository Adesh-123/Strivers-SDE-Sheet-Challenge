#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n) {
	// Write your code here.
	vector<int> ans;
        int i=0,j=0;
        while(i<m and j<n){
            if(nums1[i]>=nums2[j]){
               ans.push_back(nums2[j]);
                j++;
            }
            else{
               ans.push_back(nums1[i]);
                i++;
            }
        }
        while(i<m){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            ans.push_back(nums2[j]);
            j++;
        }
        return ans;
}