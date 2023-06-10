#include <bits/stdc++.h> 

vector<vector<string>> ans;

bool ispalindrome(string s,int l,int r){
     while(l<r){
         if(s[l]!=s[r]) return false;
         l++,r--;
     }
     return true;
}

void solver(int i,string s,vector<string> a){
    if(i==s.size()){
        // cout<<a.size()<<endl;
       ans.push_back(a);
       return;
    }
    string p="";
    for(int j=i;j<s.size();j++){
        p+=s[j];
        if(ispalindrome(s,i,j)){
            a.push_back(p);
            solver(j+1,s,a);
            a.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{   
    ans.clear(); 
    // if(s.size()==0) return ans;
    vector<string>a;
    solver(0,s,a);
    return ans;
}