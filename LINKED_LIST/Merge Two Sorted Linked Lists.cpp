#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/


Node<int>* sortTwoLists(Node<int>* list1, Node<int>* list2)

{

// Write your code here.

Node<int>*current1,*current2,*previous1,*previous2,*temp;

int flag;

if(list1==NULL){

return list2;

}

if(list2==NULL){

return list1;

}

if(list1->data < list2->data){

flag=0;

previous1=list1;

current1=list1->next;

previous2=list2;

current2=list2->next;

}

else{

flag=1;

previous1=list2;

current1=list2->next;

previous2=list1;

current2=list1->next;

}

while(previous1!=NULL && previous2!=NULL ){

if(current1!=NULL && current1->data > previous2->data){

previous1->next=previous2;

previous2->next=current1;

previous1=previous1->next;

previous2=current2;

if(current2!=NULL){

current2=current2->next;

}

}

else{

previous1=previous1->next;

if(current1!=NULL){

current1=current1->next;

}

}

}

if(previous1==NULL){

if(flag==0){

temp=list1;

}

if(flag==1){

temp=list2;

}

while(temp->next!=NULL){

temp=temp->next;

}

temp->next=previous2;

}

if(flag==0){

return list1;

}

return list2;

}

 
