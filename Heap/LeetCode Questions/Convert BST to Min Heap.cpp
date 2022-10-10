//Convert BST to Min Heap(https://www.codingninjas.com/codestudio/problems/convert-bst-to-min-heap_920498?leftPanelTab=0)

void inorder(BinaryTreeNode * root, vector<int> &v){
    if(root){
        inorder(root -> left, v);
        v.push_back(root -> data);
        inorder(root -> right, v);
    }
}

void solve(BinaryTreeNode * &root, vector<int> in, int &i){
    //pre order traversal
    if(!root) return;
    
    root -> data = in[i];
    i++;

    solve(root->left, in, i);
    solve(root -> right, in, i);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
    vector<int> in;
    inorder(root, in);
    int i = 0;
    solve(root, in, i);
    return root;
}