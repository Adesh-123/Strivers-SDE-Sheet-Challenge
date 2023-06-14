#include<bits/stdc++.h>
class Queue {
    public:
    stack<int> st;
    Queue() {
    }

    void enQueue(int val) {
        stack<int> st1;
        while(!st.empty()) st1.push(st.top()),st.pop();
        st.push(val);
        while(!st1.empty()) st.push(st1.top()),st1.pop();
    }

    int deQueue() {
        if(st.empty()) return -1;
        int val=st.top();
        st.pop();
        return val;
    }

    int peek() {
        if(st.empty()) return -1;
        return st.top();
    }

    bool isEmpty() {
        return st.empty();
    }
};