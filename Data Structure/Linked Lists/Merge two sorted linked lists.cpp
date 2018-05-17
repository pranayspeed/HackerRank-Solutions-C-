/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    if(!headA) return headB;
    if(!headB) return headA;
    
    Node* h=NULL;
    if(headA->data <= headB->data)
    {
        h = headA;
        headA=headA->next;
    }
    else
    {
        h= headB;
        headB=headB->next;
    }
    
    Node* tmp=h;
    while(headA && headB)
    {
        if(headA->data<headB->data)
        {
            tmp->next = headA;            
            headA=headA->next;
            
        }
        else
        {
            tmp->next = headB;   
            headB=headB->next;
        }
        tmp=tmp->next;        
    }
    
    if(headA) tmp->next=headA;
    else tmp->next=headB;
    return h;
}
