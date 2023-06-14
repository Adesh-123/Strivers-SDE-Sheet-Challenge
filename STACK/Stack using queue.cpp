#include <bits/stdc++.h> 
class Stack {
	queue<int> q;
    int size=0;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size==0;
    }

    void push(int element) {
        queue<int> q1;
        while(!q.empty()){
            q1.push(q.front());
            q.pop();
        }
        q.push(element);
        while(!q1.empty()){
            q.push(q1.front());
            q1.pop();
        }
        size++;
    }

    int pop() {
        if(size==0) return -1;
        int val=q.front();
        q.pop();
        size--;
        return val;
    }

    int top() {
        if(size==0) return -1;
        return q.front();
    }
};