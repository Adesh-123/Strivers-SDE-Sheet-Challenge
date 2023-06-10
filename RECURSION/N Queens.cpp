bool daigonal(int i,int j,int n,vector<vector<int>> &arr){
    for(int k=0;k<i;k++){
        if(arr[k][j]==1) return false;
    }

    int r=i,c=j;
    while(r>=0 && c>=0){
        if(arr[r][c]==1) return false;
        r--,c--;
    }
    r=i,c=j;
    while(r>=0 && c<n){
        if(arr[r][c]==1) return false;
        r--,c++;
    }
    return true;
}
vector<vector<int>> ans;

void solver(int i,int n,vector<vector<int>> &arr){
    if(i==n){
       vector<int> temp;
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++) temp.push_back(arr[i][j]);
       }
       ans.push_back(temp);
       return;
    }

    for(int j=0;j<n;j++){
        if(daigonal(i,j,n,arr)){
            arr[i][j]=1;
            solver(i+1,n,arr);
            arr[i][j]=0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
     ans.clear();
     vector<vector<int>> arr(n,vector<int>(n,0));
     solver(0,n,arr);
     return ans;
}