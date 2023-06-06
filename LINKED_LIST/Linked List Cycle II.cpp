/****************************************************************

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


*****************************************************************/

Node *firstNode(Node *head)
{   
    if(head==NULL or head->next==NULL) return NULL;
    Node* slow=head;
    Node* fast=head;
    // cout<<slow->data<<endl;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    // cout<<slow->data<<endl;
    if(fast==NULL or fast->next==NULL) return NULL;
    Node* temp=head;
    while(temp!=slow){
        slow=slow->next;
        temp=temp->next;
    }
    
    return slow;
}


















