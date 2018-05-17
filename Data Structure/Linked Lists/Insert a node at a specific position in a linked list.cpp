/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function. 
    
    Node* n = new Node;
    n->data = data;
    n->next = NULL;
    
    if(!head)
        return n;
    if(position==0)
    {
        n->next = head;
        return n;
    }
    
    
    Node* tmp=head;
    Node* t1=tmp->next;
    while(t1->next!=NULL && position>1)
    {
        tmp=t1;
        t1=t1->next;
        position--;
    }
    
    tmp->next=n;
    n->next = t1;
    
    return head;
    
}
