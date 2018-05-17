/*
Node is defined as 

typedef struct node
{
	int data;
	node * left;
	node * right;
}node;

*/

node* GetNode(node* n, int value)
{
    if(n==NULL)
    {
        n = new node;
        n->data = value;
        n->left = NULL;
        n->right = NULL;
    }
    else
    {
        if(n->data > value)
        {
            n->left = GetNode(n->left, value);            
        }
        else
        {
            n->right = GetNode(n->right, value); 
        }
    }
    return n;
}

node * insert(node * root, int value) {
    
    root = GetNode(root, value);
	return root;
}