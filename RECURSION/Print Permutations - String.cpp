#include <bits/stdc++.h> 
string next_permutation(string s){
      int i=0;
      for(i=s.size()-2;i>=0;i--){
          if(s[i]<s[i+1]) break;
      }
      
      if(i==-1){
          reverse(s.begin(),s.end());
          return s;
      }

      for(int j=s.size()-1;j>i;j--){
         if(s[j]>s[i]){
             swap(s[j],s[i]);
             break;
         }
      }
      
      reverse(s.begin()+i+1,s.end());
      return s;
}

vector<string> findPermutations(string &s) {
    int n=s.size();
    sort(s.begin(),s.end());
    int fact=1;
    for(int i=1;i<=n;i++) fact*=i;
    vector<string> ans;
    ans.push_back(s);
    fact--;
    while(fact--){
        s=next_permutation(s);
        ans.push_back(s);
    }
    return ans;
}