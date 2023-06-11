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

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node* temp=firstHead;
    Node* ptr=secondHead;
    int i=0,j=0;
    while(temp!=NULL){
        i++;
        temp=temp->next;
    }
     while(ptr!=NULL){
        j++;
        ptr=ptr->next;
    }
    Node* htr;
    Node* str;
    if(i>=j){
        htr=firstHead;
        str=secondHead;
    }
    else{
         htr=secondHead;
         str=firstHead;
    }
    int n=0;
    while(n!=abs(i-j)){
        htr=htr->next;
        n++;
    }
    while(htr!=NULL && str!=NULL){
        if(htr==str) break;
        htr=htr->next;
        str=str->next;
    }
   return str;
}