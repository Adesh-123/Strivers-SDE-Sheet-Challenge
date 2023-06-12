#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	vector<int> nums;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			nums.push_back(a[i]+b[j]);
		}
	}
	sort(nums.begin(),nums.end());
    vector<int> ans;
	int i=1;
	while(i<=k){
		ans.push_back(nums[nums.size()-i]);
		i++;
	}
	return ans;
}
