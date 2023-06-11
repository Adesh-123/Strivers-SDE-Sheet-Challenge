#include <bits/stdc++.h> 
vector<string> a;

void solver(int i,string &s,map<string,int> m,vector<string> &ans){
    if(i==s.size()){
        string t="";
        for(int j=0;j<ans.size();j++){
            t+=ans[j];
            if(j!=ans.size()-1) t+=" ";
        }
        a.push_back(t);
        return;
    }
    

    string t="";
    for(int j=i;j<s.size();j++){
       t+=s[j];
       if(m.find(t)!=m.end()){
           ans.push_back(t);
           solver(j+1,s,m,ans);
           ans.pop_back();
       }
    }
}



vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    map<string,int> m;
    for(int i=0;i<dictionary.size();i++){
        m[dictionary[i]]++;
    }
    a.clear();
    vector<string> ans;
    solver(0,s,m,ans);
    return a;
}