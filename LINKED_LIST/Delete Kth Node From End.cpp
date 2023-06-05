/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    Node* fast=head;
    Node* slow=head;

    Node* prev=NULL;
    while(K>1){
        fast=fast->next;
        K--;
    }

    while(fast->next!=NULL){
       prev=slow;
       slow=slow->next;
       fast=fast->next;
    }

    if(prev==NULL){
        return head->next;
    }else{
        prev->next=slow->next;
    }
    return head;
}
