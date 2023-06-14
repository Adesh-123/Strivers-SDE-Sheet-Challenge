#include <bits/stdc++.h> 

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

int maximumXor(vector<int> A)
{   
    Node* root=new Node();
    for(int i=0;i<A.size();i++){
        insert(root,A[i]);
    }  

    int maxi=0;
    for(int i=0;i<A.size();i++){
        maxi=max(maxi,maxxor(root,A[i]));
    }
    return maxi;
}