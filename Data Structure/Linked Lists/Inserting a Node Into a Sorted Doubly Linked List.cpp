/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method. 
    
    Node* p=head;
    Node* n = new Node;
    n->data=data;
    n->next=NULL;
    n->prev=NULL;
    if(!head)
        return n;
    
    if(p->data > data)
    {
        n->next=p;
        p->prev=n;
        return n;
    }
    Node*q=p;
    while(p)
    {
        if(p->data>data)
        {
            q->next=n;
            n->prev=q;
            n->next =p;
            p->prev=n;
            break;
        } 
        q=p;
        p=p->next;
    }
    
    if(p==NULL)
    {
        q->next=n;
        n->prev=q;
    }
    
    return head;
    
}
