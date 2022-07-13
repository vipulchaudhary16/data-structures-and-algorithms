# [Kth Ancestor in a Tree](https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/)

```cpp
Node * solve(Node * root, int &k, int node){
    if(root == NULL) 
        return NULL;
    
    if(root -> data == node)
        return root;
    
    Node * left = solve(root -> left, k, node);
    Node * right = solve(root -> right, k , node);
    
    if(left != NULL and right == NULL)
    {
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        else
            return left;
    }
    
    if(left == NULL and right != NULL)
    {
        k--;
        if(k <= 0){
            //ans lock
            k = INT_MAX;
            return root;
        }
        else
            return right;
    }
    
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node * ans = solve(root, k, node);
    
    return (ans == NULL || ans -> data == node ? -1 : ans -> data);
}
```