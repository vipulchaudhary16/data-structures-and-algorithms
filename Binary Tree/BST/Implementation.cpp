#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int val)
    {
        this -> val = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

TreeNode * insertIntoBST(TreeNode * root, int data){
    if(root == NULL)
    {
        root = new TreeNode(data);
        return root;
    }

    if(data > root -> val) root -> right = insertIntoBST(root -> right, data);
    else  root -> left = insertIntoBST(root -> left, data);

    return root;
}

void takeInputs(TreeNode * root){
    int data;
    cin>>data;

    while(data != -1){
        insertIntoBST(root, data);
        cin>>data;
    }
}

int main()
{
    
    return 0;
}