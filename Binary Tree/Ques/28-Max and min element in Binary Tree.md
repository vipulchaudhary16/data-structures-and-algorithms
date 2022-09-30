# [Max and min element in Binary Tree](https://practice.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1)

```cpp
class Solution
{
public:
    int findMax(Node *root)
    {
        if(root == NULL)
            return INT_MIN;
        
        int res = root -> data;    
        int l = findMax(root -> left);
        int r = findMax(root -> right);
        
        return max(res, max(l,r));
    }
    int findMin(Node *root)
    {
        if(root == NULL)
            return INT_MAX;
        
        int res = root -> data;    
        int l = findMin(root -> left);
        int r = findMin(root -> right);
        
        return min(res, min(l,r));

    }
};
```