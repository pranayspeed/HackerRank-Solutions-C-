/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
  // Complete this method
    
    Node* node =new Node;
    node->data=data;
    node->next=NULL;
    
    if(!head)
        return node;
    
    Node* tmp=head;
    
    while(tmp->next!=NULL)
    {
        tmp = tmp->next;
    }
    
    tmp->next=node;
    
    return head;
    
}
