
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void Level(node* n, int l, int cl)
{
    if(n==NULL) return;
    if(l==cl)
    {
        cout<<n->data<<" ";
    }
    Level(n->left, l+1,cl);
    Level(n->right, l+1,cl);
}

void Traverse(node* n)
{

}

int height(node* n)
{
    if(n==NULL) return -1;
    int h1 = height(n->left);
    int h2 = height(n->right);
    
    if(h1>h2) return h1+1;
    else return h2+1;
    
}

void levelOrder(node * root) {
  
    int h = height(root);
   // cout<<h<<" ";
    for(int i=0;i<=h;i++)
    {
        Level(root,0,i);
    }
}
