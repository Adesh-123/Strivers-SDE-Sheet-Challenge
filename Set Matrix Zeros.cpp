#include <bits/stdc++.h>

void settingallrowandcolumnzero(int r,int c,int n,int m,vector<vector<int>>&matrix){
	for(int i=0;i<m;i++) matrix[r][i]=0;
	for(int j=0;j<n;j++) matrix[j][c]=0;
}

void setZeros(vector<vector<int>> &matrix)
{
	int n=matrix.size();
	int m=matrix[0].size();
	vector<vector<int>> pos;
	for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				int r=i,c=j;
				pos.push_back({r,c});
			}
		}
	}

	for(int i=0;i<pos.size();i++){
		settingallrowandcolumnzero(pos[i][0],pos[i][1],n,m,matrix);
	}
}