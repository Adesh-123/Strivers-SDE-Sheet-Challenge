#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    vector<int>arr;
    int size=0;
    int len=0;
    
    Stack(int capacity) {
        arr=vector<int>(capacity);
        size=capacity;
    }

    void push(int num) {
        if(len==size) return;
        arr[len]=num;
        len++;
    }

    int pop() {
        if(len==0) return -1;
        int val=arr[len-1];
        len--;
        return val;
    }
    
    int top() {
        if(len==0) return -1;
        return arr[len-1];
    }
    
    int isEmpty() {
        return len==0;
    }
    
    int isFull() {
        return (len==size);
    }
    
};