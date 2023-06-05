#include <bits/stdc++.h> 
int reversePairs(vector<int> &arr, int n){
	// Write your code here.

	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(2*arr[i]<arr[j]) count++;
		}
	}	
	return count;
}