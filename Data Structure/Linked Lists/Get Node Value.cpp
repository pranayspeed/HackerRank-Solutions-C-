/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    if(head->next==NULL)
    return head->data;
    
    Node* p=NULL,*q=head,*r=head->next;
    
    while(q->next)
    {
        q->next=p;
        p=q;
        q=r;
        r=r->next;
    }
    q->next=p;
    while(positionFromTail-->0)
    {
        q=q->next;
    }
    
    return q->data;
}
