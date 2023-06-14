#include<bits/stdc++.h>


bool check(int i,int j,int n,int m){
    return (i<0 or i>=n or j<0 or j>=m);
}

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
   int maxi=0;
   queue<pair<int,int>> pq;
   int time=-1;
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(grid[i][j]==2) pq.push({i,j});
       }
   }
   
   vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};

   while(!pq.empty()){
       int size=pq.size();
    //    cout<<pq.size()<<endl;
       time++;
       while(size--){
         int r=pq.front().first;
         int c=pq.front().second;
         pq.pop();
         
         for(auto z:dirs){
             int x=r+z.first;
             int y=c+z.second;

             if(check(x,y,n,m)) continue;
             else if(grid[x][y]==2 or grid[x][y]==0) continue;

             grid[x][y]=2;
             pq.push({x,y});
         }
       }
   }

   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(grid[i][j]==1) return -1;
       }
   }

   return time==-1?0:time;
}