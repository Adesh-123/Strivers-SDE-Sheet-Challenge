int singleNonDuplicate(vector<int>& arr)
{
	int low=0;
	int high=arr.size()-1;
	int mid;
	while(low<=high){
		mid=(low+high)/2;
        // cout<<mid<<endl;
		if(mid%2==0){
			if(mid+1<arr.size() && arr[mid]==arr[mid+1]){
				low=mid+1;
			}
			else if(mid-1>=0 && arr[mid]==arr[mid-1]){
				high=mid-1;
			}else{
				return arr[mid];
			}
		}else{
			if(mid+1<arr.size() && arr[mid]==arr[mid+1]){
				high=mid-1;
			}else if(mid-1>=0 && arr[mid]==arr[mid-1]){
                low=mid+1;
			}
			else return arr[mid];
		}
	}
		return arr[mid];
}