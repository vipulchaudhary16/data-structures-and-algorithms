# [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        
        TreeNode * right = root -> right;
        root -> right = root -> left;
        root -> left = right;
        
        invertTree(root -> left);
        invertTree(root -> right);
        
        return root;
    }
};
```