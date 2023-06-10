#include <bits/stdc++.h> 

vector<vector<int>> ans;
void solver(int i,int j,int n,vector<vector<int>> &maze,vector<vector<int>> &path){
  if(i==n-1 && j==n-1){
    path[i][j]=1;
    vector<int> temp;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) temp.push_back(path[i][j]);
    ans.push_back(temp);
    path[i][j]=0;
    return ;
  }else if(i<0 or j<0 or i>=n or j>=n) return;
  else if(maze[i][j]==0 or path[i][j]==1) return;

  path[i][j]=1;
  solver(i+1,j,n,maze,path);
  solver(i,j+1,n,maze,path);
  solver(i-1,j,n,maze,path);
  solver(i,j-1,n,maze,path);
  path[i][j]=0;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<vector<int>> path(n,vector<int>(n,0));
  solver(0,0,n,maze,path);
  return ans;
}