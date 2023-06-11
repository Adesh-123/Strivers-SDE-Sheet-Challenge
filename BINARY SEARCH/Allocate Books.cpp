#include <bits/stdc++.h> 

bool ispossible(vector<int> &time,long long mid,int n){
	long long sum=0;
    int days=1;
	int m=time.size();
	for(int i=0;i<m;i++){
		if(sum+time[i]>mid){
			sum=time[i];
			days++;
		}else{
			sum=sum+time[i];
		}
	}
	return days<=n;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	int maxi=INT_MIN;
	long long sum=0;
	for(int i=0;i<m;i++){
		sum+=time[i];
		maxi=max(maxi,time[i]);
	}

	long long low=maxi;
	long long high=sum;
    long long ans=sum;
	while(low<=high){
       long long mid=(low+high)/2;

	   if(ispossible(time,mid,n)){
		   ans=mid;
		   high=mid-1;
	   }else{
		   low=mid+1;
	   }
	}
	return ans;
}