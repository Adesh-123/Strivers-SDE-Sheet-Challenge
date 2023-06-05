#include <bits/stdc++.h> 

vector<vector<int>> dp;
int solver(int i,int j,int m,int n){
	if(i==m-1 && j==n-1) return 1;
	else if(i>=m || i<0 || j>=n || j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    
	return dp[i][j]=solver(i+1,j,m,n)+solver(i,j+1,m,n);
}

int uniquePaths(int m, int n) {
	// Write your code here.
    dp=vector<vector<int>>(m,vector<int>(n,-1));
	return solver(0,0,m,n);
}