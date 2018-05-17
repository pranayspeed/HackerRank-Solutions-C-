/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method. 
    if(!head || !head->next) return head;
    
    
    Node *p=head;
    Node *q= p->next;
    
    while(q)
    {
        p->next=p->prev;
        p->prev=q;
        p=q;
        q=q->next;        
    }
    
    p->next=p->prev;
    p->prev=NULL;
    
    return p;
    
    
}
