# [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)

```cpp
class Solution
{
public:
    int height(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        int l = height(node->left);
        int r = height(node->right);

        return (max(l, r) + 1);
    }

    bool isBalanced(TreeNode *root)
    {
        if(root == NULL)
            return true;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool balance = abs(height(root->left) - height(root->right)) <= 1;

        return (left && right && balance);
    }
};
```
> Time Complexity : O(n<sup>2</sup>) --> Nahi chalega bro

## Chalo pair use kar ke kar dete h na
```cpp
class Solution {
public:
    pair<bool, int> isBalanced_fast(TreeNode * root){
        if(root == NULL)
            return {true, 0};
        
        pair<bool, int> left = isBalanced_fast(root -> left);
        pair<bool, int> right = isBalanced_fast(root -> right);
        
        return {left.first && right.first && abs(left.second - right.second) <= 1,
               (max(left.second, right.second) + 1)
               };
    }
    bool isBalanced(TreeNode* root) {
        return isBalanced_fast(root).first;
    }
};
```
> Time Complexity : **O(n)**