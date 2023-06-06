/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     int n=0;
     Node* temp=head;
     while(temp){
          n++;
          temp=temp->next;
     }
     k=k%n;
     // cout<<k<<endl;
     if(k==0) return head;
     int len=n-k;
     Node* prev=NULL;
     temp=head;
     while(len>0){
          prev=temp;
          temp=temp->next;
          len--;
     }
     prev->next=NULL;
     Node* curr=temp;
     while(curr->next){
          curr=curr->next;
     }
     curr->next=head;
     return temp;
}