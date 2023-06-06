#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if(head==NULL) return NULL;
         LinkedListNode<int>* temp=head;
        while(temp!=NULL){
            LinkedListNode<int>* tempnext=temp->next;
             LinkedListNode<int>* copylist=new  LinkedListNode<int>(temp->data);
            temp->next=copylist;
            copylist->next=tempnext;
            temp=temp->next->next;
        }
         LinkedListNode<int>* itr=head;
        while(itr!=NULL){
            if(itr->random!=NULL)  itr->next->random=itr->random->next;
            else itr->next->random=NULL;
            itr=itr->next->next;
        }
         LinkedListNode<int>* dummy=new  LinkedListNode<int>(-1);
         LinkedListNode<int>* answer=dummy;
         LinkedListNode<int>* trav=head;
         LinkedListNode<int>* front=head->next->next;
        while(trav!=NULL){
            answer->next=trav->next;
            trav->next=front;
            if(front!=NULL) front=front->next->next;
            trav=trav->next;
            answer=answer->next;
        }
        answer->next=NULL;
        
        return dummy->next;
        
}
