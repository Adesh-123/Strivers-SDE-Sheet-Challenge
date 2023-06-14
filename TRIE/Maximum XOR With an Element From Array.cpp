#include<bits/stdc++.h>
class Node{
    Node* Link[2];

    public:
      bool contianKey(int bit){
          return (Link[bit]!=NULL);
      }

      void put(int bit,Node* node){
          Link[bit]=node;
      }

      Node* get(int bit){
          return Link[bit];
      }
};

void insert(Node* root,int n){
    Node* node=root;
     for(int i=31;i>=0;i--){
         int bit=(n>>i)&1;
         if(!node->contianKey(bit)){
             node->put(bit,new Node());
         }
         node=node->get(bit);
     }
}


int maxxor(Node* root,int n){
    Node* node=root;
    int maxi=0;
    for(int i=31;i>=0;i--){
        int bit=(n>>i)&1;
        if(node->contianKey(!bit)){
            maxi=maxi | (1<<i);
            node=node->get(!bit);
        }else{
            node=node->get(bit);
        }
    }
    return maxi;
}
static bool comp(vector<int> a,vector<int> b){
        return a[1]<b[1];
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	    sort(arr.begin(),arr.end());
        vector<vector<int>> q;
        for(int i=0;i<queries.size();i++){
            vector<int> a;
            a.push_back(queries[i][0]);
            a.push_back(queries[i][1]);
            a.push_back(i);
            q.push_back(a);
        }
        sort(q.begin(),q.end(),comp);
        int j=0;
        vector<int> ans(q.size());
		Node* root=new Node();
        for(int i=0;i<q.size();i++){
            int val=q[i][1];
            while(j<arr.size() and arr[j]<=val){
                insert(root,arr[j]);
                j++;
            }
            if(j==0) ans[q[i][2]]=-1;
            else ans[q[i][2]]=maxxor(root,q[i][0]);
        }
        return ans;
}