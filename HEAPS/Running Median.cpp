#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>> mini;

    for(int i=0;i<n;i++){
        int val=arr[i];

        if(maxi.size()==0){
            maxi.push(val);
        }else if(mini.size()==0){
            if(val>=maxi.top()){
                mini.push(val);
            }else{
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(val);
            }
        }else{
            if(maxi.size()==mini.size()){
                if(val>mini.top()){
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(val);
                }else{
                    maxi.push(val);
                }
            }else{
                if(val<maxi.top()){
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(val);
                }else{
                    mini.push(val);
                }
            }
        }
        if(i%2==0){
            cout<<maxi.top()<<" ";
        }else{
            cout<<(maxi.top()+mini.top())/2<<" ";
        }
    }
    cout<<endl;
}