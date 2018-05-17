/*
Node is defined as 

typedef struct node
{
	int data;
	node *left;
	node *right;
}node;

*/


node *lca(node *root, int v1,int v2)
{
    node* n = root;
    while(n)
    {
        if(n->data < v1 && n->data <v2)
            n=n->right;
        else if(n->data >v1 && n->data >v2)
            n=n->left;
        else
            break;
    }
    return n;
}