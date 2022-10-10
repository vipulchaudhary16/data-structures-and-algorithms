# [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)

```cpp
class Solution {
public:
    void solve(TreeNode * root, vector<int> &v){
        if(root){
            solve(root -> left, v);
            v.push_back(root->val);
            solve(root -> right, v);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        solve(root, in);
        return in;
    }
};
```
