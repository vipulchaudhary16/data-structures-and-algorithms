# [Path Sum](https://leetcode.com/problems/path-sum/)

```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        
        targetSum -= root -> val;
        if(root -> left == NULL and root -> right == NULL and targetSum == 0)
            return true;
        
        return (hasPathSum(root -> left , targetSum) || hasPathSum(root -> right , targetSum));
    }
};
```