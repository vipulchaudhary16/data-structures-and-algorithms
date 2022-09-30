## [ Root Equals Sum of Children](https://leetcode.com/problems/root-equals-sum-of-children/)

```cpp
class Solution {
public:
    bool checkTree(TreeNode* root) {
        return root -> val == (root->left->val + root->right->val);
    }
};
```