# [Same Tree](https://leetcode.com/problems/same-tree/)

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL and q == NULL)
            return true;
        
        if(p == NULL || q == NULL)
            return false;
        
        if(p -> val != q -> val)
            return false;
        
        return (isSameTree(p->left, q->left) and isSameTree(p->right, q->right));
        
    }
};
```