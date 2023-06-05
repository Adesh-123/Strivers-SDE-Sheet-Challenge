#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int i=0;
	while(i<n){
		if(arr[i]!=i+1){
			if(arr[arr[i]-1]==arr[i]) i++;
			swap(arr[arr[i]-1],arr[i]);
	    	// cout<<arr[arr[i]-1]<<" "<<arr[i]<<endl;
		}else i++;
	}

	int M,R;
	for(int i=0;i<n;i++){
		if(arr[i]!=i+1){
			R=arr[i];
			M=i+1;
			break;
		}
	}
	pair<int,int> p=make_pair(M,R);
	return p;
}
