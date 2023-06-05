#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int>* reverseLinkedList(LinkedListNode<int>* head){
    LinkedListNode<int>* curr=head;
    LinkedListNode<int>* prev=NULL;
    LinkedListNode<int>* nextptr=NULL;

    while(curr){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.

     LinkedListNode<int>* ptr=head;
        bool answer=true;
        if(ptr==NULL or ptr->next==NULL)  return true;
              
        LinkedListNode<int>* slow=head;
        LinkedListNode<int>* fast=head;
        while(fast->next && fast->next->next){
           slow=slow->next;
           fast=fast->next->next; 
        }
        
        LinkedListNode<int>* qtr=reverseLinkedList(slow->next);
        slow->next=NULL;
        while(ptr!=NULL && qtr!=NULL ){
           if(ptr->data!=qtr->data){      
               return false;
           }
            ptr=ptr->next;
            qtr=qtr->next;
        }
        return true;
}