/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    
    if(!head)
        return NULL;
    
    Node* p=head;
    Node* q=p;
    Node*r=p->next;
    while(p->next)
    {
        q=p;
        r=p->next;
        while(r && q && q->data == r->data)
        {
            r=r->next;
            delete q->next;
            q->next=r;
        }
        if(!r)
            break;
        p=r;            
    }
    return head;
}
