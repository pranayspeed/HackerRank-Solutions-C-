/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
  // Complete this method
    if(head==NULL || head->next==NULL)
        return head;
    
    Node* p=NULL,*q=head,*r=head->next;
    
    while(q->next)
    {
        q->next=p;
        p=q;
        q=r;
        r=r->next;
    }
    q->next=p;
    return q;
 
}
