/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/

int PrintCode(node* n, string s, int l)
{
    if(n->data!='\0')
    {
        cout<< n->data;       
    }
    else
    {
        if(s[l]=='0')
          l=  PrintCode(n->left, s, l+1);
        else
          l=  PrintCode(n->right, s, l+1);
    }
    return l;
}


void decode_huff(node * root,string s)
{
    int l=0;
    while(l!=s.length())
    {
        l=PrintCode(root, s, l);
    }
}