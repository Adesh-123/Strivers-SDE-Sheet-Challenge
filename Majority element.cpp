#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	map<int,int>m;
	for(int i=0;i<n;i++){
		m[arr[i]]++;
	}

	int count=n/2;
	for(auto curr:m){
		if(curr.second>count) return curr.first;
	}
	return -1;

}