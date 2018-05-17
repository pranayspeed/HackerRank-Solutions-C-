/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(!head) return false;
    
    Node* p=head,*q=head;
   
    while (p && q && p->next)
    {
        p = p->next;
        q  = q->next->next;

        if (p == q)
        {
            return true;
        }
    }
    
    return false;
    
}
