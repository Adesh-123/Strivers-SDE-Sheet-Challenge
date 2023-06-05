#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    // int maxlen=0;
    // for(int i=0;i<input.size();i++){
    //     vector<int> vis(26,0);
    //     for(int j=i;j<input.size();j++){
    //        if(vis[input[j]-'a']>0){
    //            maxlen=max(maxlen,j-i);
    //            break;
    //        }else{
    //            vis[input[j]-'a']++;
    //        }

    //        if(j==input.size()-1){
    //            maxlen=max(maxlen,j-i+1);
    //        }
    //     }
    // }
    // return maxlen;

    //  map<char,int> m;
    //  int j=0;
    //  int maxlen=0;
    //  for(int i=0;i<input.size();i++){
    //      if(m.find(input[i])!=m.end()){
    //         //  cout<<input[i]<<" "<<m[input[i]]<<endl;
    //          if(m[input[i]]>=j){
    //              j=m[input[i]]+1;
    //          }
    //      }
    //      m[input[i]]=i;
    //      maxlen=max(maxlen,i-j+1);
    //     //  cout<<j<<endl;
    //  }


     vector<int> m(26,-1);
     int j=0;
     int maxlen=0;
     for(int i=0;i<input.size();i++){
         if(m[input[i]-'a']!=-1){
             if(m[input[i]-'a']>=j){
                 j=m[input[i]-'a']+1;
             }
         }
         m[input[i]-'a']=i;
         maxlen=max(maxlen,i-j+1);
     }
     return maxlen;

}