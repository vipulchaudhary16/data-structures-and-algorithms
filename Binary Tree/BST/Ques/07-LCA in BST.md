# [LCA in BST](https://www.codingninjas.com/codestudio/problems/lca-in-a-bst_981280?leftPanelTab=0)

```cpp
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    if(!root) return NULL;
        
    if(root -> data == P -> data or root -> data == Q -> data) return root;
    
    TreeNode<int>* left = LCAinaBST(root -> left, P,Q);
    TreeNode<int>* right = LCAinaBST(root -> right, P,Q);
    
    if(right and left) return root;
    else if(!left and right) return right;
    else if(left and !right) return left;
    else return NULL;
}
```

## Another Approach
```cpp
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    if(!root) return NULL;
    
    if(root -> data > P -> data and root -> data > Q -> data)
        return LCAinaBST(root -> left, P, Q);
    
    if(root -> data < P -> data and root -> data < Q -> data)
        return LCAinaBST(root -> right, P, Q);
    
    return root;
}
```