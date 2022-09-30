# [Lowest Common Ancestor in a Binary Tree](https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/)

### [LeetCode Link](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

```cpp
class Solution
{
    public:
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Base case
        if(root == NULL)
            return NULL;
        
        //We got our answer    
        if(root -> data == n1 || root -> data == n2)
            return root;
        
            
        Node * left = lca(root -> left, n1, n2);
        Node * right = lca(root -> right, n1, n2);
        
        if(left != NULL and right != NULL)
            return root;
        
        else if(left != NULL and right == NULL)
            return left;
            
        else if(right != NULL and left == NULL)
            return right;
        
        else return NULL;
    }
};
```