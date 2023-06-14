#include <bits/stdc++.h> 
class Queue {
public:
    vector<int> arr;
    int start=0;
    int end=0;
    Queue() {
      arr=vector<int>(10000);
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return (start==end);
    }

    void enqueue(int data) {
        arr[end]=data;
        end++;
    }

    int dequeue() {
        if(start==end) return -1;
        start++;
        return arr[start-1];
    }

    int front() {
        if(start==end) return -1;
        return arr[start];
    }
};