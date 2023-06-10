#include <bits/stdc++.h> 

bool ispossible(int node,int col,vector<vector<int>> &mat,vector<int> &color){
    for(int i=0;i<mat.size();i++){
        if(node!=i && mat[node][i]==1 && color[i]==col) return false;
    }
    return true;
}

bool solver(int node,int m,vector<vector<int>> &mat,vector<int> &color){
    if(node==mat.size()) return true;

    for(int col=1;col<=m;col++){
        if(ispossible(node,col,mat,color)){
            color[node]=col;
            if(solver(node+1,m,mat,color)) return true;
            color[node]=0;
        }
    }
    return false;
}



string graphColoring(vector<vector<int>> &mat, int m) {
    vector<int> color(mat.size(),0);
    if(solver(0,m,mat,color)) return "YES";
    return "NO";
}