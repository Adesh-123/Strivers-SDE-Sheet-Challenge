int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int i=0;
	int j=0;
	while(i<n){
		if(arr[i]!=arr[j]){
           j++;
		   arr[j]=arr[i];
		}
		i++;
	}
	return j+1;
}