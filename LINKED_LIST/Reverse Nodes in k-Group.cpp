#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node* solver(Node* head,int n,int b[],int i){
	//  cout<<head->data<<endl;
	 if(i==n) return head;
	 else if(head==NULL) return NULL;
	 else if(b[i]==0) return solver(head,n,b,i+1);
	 else if(b[i]==1){
       Node* curr=head;
	   curr->next=solver(head->next,n,b,i+1);
	   return curr;
	 }
	 Node* prev=head;
	 Node* start=head;
	 Node* curr=head->next;
	 Node* nextptr=NULL;
	 int len=b[i]-1;
	 while(len-- && curr!=NULL){
		 nextptr=curr->next;
         curr->next=prev;
		 prev=curr;
		 curr=nextptr;
	 }

	 start->next=solver(curr,n,b,i+1);
	 return prev;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	return solver(head,n,b,0);

}