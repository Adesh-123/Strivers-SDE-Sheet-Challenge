#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    int i=0;
	while(i<n){
		if(arr[i]!=i+1){
           if(arr[arr[i]-1]==arr[i]) return arr[i];
		   swap(arr[arr[i]-1],arr[i]);
		}else i++;
	}
	return -1;
}
