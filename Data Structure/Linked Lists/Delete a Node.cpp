/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  // Complete this method
    
    if(!head)
        return NULL;
    Node* tmp=head;
    if(position==0)
    {
        head = head->next;
        delete tmp;
        return head;
    }

    Node* t1=tmp;
    while(position>1)
    {
        t1=t1->next;
        position--;
    }
    
    tmp=t1;
    t1=t1->next;
    t1=t1->next;
    delete tmp->next;
    tmp->next = t1;

    return head;
}
