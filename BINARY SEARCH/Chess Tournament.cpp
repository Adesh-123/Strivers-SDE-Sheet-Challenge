#include <bits/stdc++.h> 

bool ispossible(vector<int> &positions,int mid,int c){
     int players=1;
	 int index=0;
	 while(index<positions.size()){
      auto i=lower_bound(positions.begin(),positions.end(),positions[index]+mid)-positions.begin();
	  if(i!=positions.size()){
		  players++;
	  }
	  index=i;
	 }
	 return players>=c;
}

int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(),positions.end());
	int low=1;
	int high=positions[n-1]-positions[0];
	int ans=0;
	while(low<=high){
		int mid=(low+high)/2;
		if(ispossible(positions,mid,c)){
			ans=mid;
			low=mid+1;
		}else{
            high=mid-1;
		}
	}
    
	return ans;

}