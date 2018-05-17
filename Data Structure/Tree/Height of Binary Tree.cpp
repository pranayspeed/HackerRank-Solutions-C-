
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    
    int Traverse(Node* n, int l){
        
        if(!n) return l-1;
        
        int hl = Traverse(n->left, l+1);
        int hr = Traverse(n->right, l+1);
        if(hl>hr)
            return hl;
        else
            return hr;
    }

    int height(Node* root) {
        // Write your code here.
        int h=0;
        if(!root)
            return 0;
        Node* p=root;
        h=Traverse(root, 0);
       
        return h;
    }
  