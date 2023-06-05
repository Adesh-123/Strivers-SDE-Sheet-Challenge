/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node* ans=new Node(-1);
    Node* temp=ans;

    int sum=0;
    int rem=0;
    while(num1!=NULL && num2!=NULL){
       sum=num1->data+num2->data+rem;
       Node* ptr=new Node(sum%10);
       ptr->next=NULL;
       rem=sum/10;
       num1=num1->next;
       num2=num2->next;
       temp->next=ptr;
       temp=temp->next;
    }

    while(num1!=NULL){
        sum=num1->data+rem;
        Node* ptr=new Node(sum%10);
        rem=sum/10;
        ptr->next=NULL;
        num1=num1->next;
        temp->next=ptr;
        temp=temp->next;
    }

    while(num2!=NULL){
        sum=num2->data+rem;
        Node* ptr=new Node(sum%10);
        rem=sum/10;
        ptr->next=NULL;
        num2=num2->next;
        temp->next=ptr;
        temp=temp->next;
    }

    while(rem>0){
       Node* ptr=new Node(rem%10);
       rem=rem/10;
       ptr->next=NULL;
       temp->next=ptr;
       temp=temp->next;
    }
    return ans->next;
}
