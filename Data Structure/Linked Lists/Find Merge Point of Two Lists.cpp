/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    Node* p=headA;
    Node*q=p->next;
    while(q)
    {
        p->next=NULL;
        p=q;
        q=q->next;
    }
    
    while(headB->next)
    {
        headB=headB->next;
    }
    
    return headB->data;
    
}
