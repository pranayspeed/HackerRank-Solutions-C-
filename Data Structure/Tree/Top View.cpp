/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void Left(node* n)
{
    if(!n) return;
    Left(n->left);
    cout<< n->data<<" ";
}

void Right(node* n)
{
    if(!n) return;
    cout<< n->data<<" ";
    Right(n->right);
}

void topView(node * root) {
 
    Left(root);
    Right(root->right);
    
}
