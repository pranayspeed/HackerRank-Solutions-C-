/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void ReversePrint(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    Node* tmp=head;
    if(!head)
        return;
    if(tmp->next==NULL)
        cout<<tmp->data<<endl;
    
    Node* l=NULL;
    while(tmp)
    {
        Node* n=new Node;
        n->data = tmp->data;
        n->next = l;
        l=n;
        tmp=tmp->next;
    }
    
    
    while(l)
    {
        cout<<l->data<<endl;
        l=l->next;
    }
}
