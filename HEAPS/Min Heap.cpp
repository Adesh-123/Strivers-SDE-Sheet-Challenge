#include <bits/stdc++.h> 

void heapify(vector<int> &arr,int i){
    int smallest=i;
    int n=arr.size();
    int left=2*i+1;
    if(left<n && arr[left]<arr[smallest]){
        smallest=left;
    }
    int right=2*i+2;
    if(right<n && arr[right]<arr[smallest]){
        smallest=right;
    }

    if(smallest!=i){
        swap(arr[i],arr[smallest]);

        heapify(arr,smallest);
    }
}

void insert(vector<int> &arr,int x){
    arr.push_back(x);
    int i=arr.size()-1;

    while(i!=0 && arr[(i-1)/2]>arr[i]){
        swap(arr[(i-1)/2],arr[i]);
        
        i=(i-1)/2;
    }
}

int deletes(vector<int> &arr){
    int x=arr[0];
    swap(arr[0],arr[arr.size()-1]);
    arr.pop_back();
    if(arr.size()==0) return x;

    heapify(arr,0);
    return x;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> arr;
    vector<int> ans;
    for(int i=0;i<n;i++){
        int x=q[i][0];
        if(x==0){
            insert(arr,q[i][1]);
        }else{
            int y=deletes(arr);
            ans.push_back(y);
        }
    }
    return ans;
}
