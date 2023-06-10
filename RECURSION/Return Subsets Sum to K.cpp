
vector<vector<int>> a;
void solver(int i,int sum,int n,int k,vector<int> &arr,vector<int> &ans){
    if(i==n){
       if(sum==k){
         a.push_back(ans);
       }
       return;
    }

    solver(i+1,sum,n,k,arr,ans);
    ans.push_back(arr[i]);
    solver(i+1,sum+arr[i],n,k,arr,ans);
    ans.pop_back();
}


vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{   
    a.clear();
    vector<int> ans;
    solver(0,0,n,k,arr,ans);
    return a;
}