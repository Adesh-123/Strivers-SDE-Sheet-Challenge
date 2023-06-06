#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
	for(int i=0;i<n-2;i++){
        int target=K-arr[i];
		int j=i+1;
		int k=n-1;
		if(i==0 || (i>0 && arr[i]!=arr[i-1])){
           while(j<k){
			int sum=arr[j]+arr[k];
			if(sum==target){
				vector<int>a;
				a.push_back(arr[i]);
				a.push_back(arr[j]);
				a.push_back(arr[k]);
                ans.push_back(a);
				int val1=arr[j];
				int val2=arr[k];
				while(j<k && arr[j]==val1) j++;
				while(j<k && arr[k]==val2) k--;
			}else if(sum>target) k--;
	  		else j++;a
		   }
		}
	}
	return ans;
}