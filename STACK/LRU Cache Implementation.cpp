#include<bits/stdc++.h>
class LRUCache
{
public:
    class Node{
        public:
          int key;
          int value;
          Node* next;
          Node* prev;

          Node(int key,int value){
              this->key=key;
              this->value=value;
          }
    };
    
    Node*head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);
    map<int,Node*>m;
    int size=0;

    
    LRUCache(int capacity)
    { 
        size=capacity;
        head->next=tail;
        tail->prev=head;
        
    }

    void insert(Node* node){
        Node* headnext=head->next;
        node->next=headnext;
        head->next=node;
        headnext->prev=node;
        node->prev=head;
    }

    void deletes(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    int get(int key)
    {
        if(m.find(key)!=m.end()){
           Node* node=m[key];
           int val=node->value;
           m.erase(key);
           deletes(node);
           insert(node);
           m[key]=head->next;
           return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if(m.find(key)!=m.end()){
            Node* node=m[key];
            m.erase(key);
            deletes(node);
        }
        if(m.size()==size){
            m.erase(tail->prev->key);
            deletes(tail->prev);
        }
        insert(new Node(key,value));
        m[key]=head->next;
    }
};
