## [Find a Corresponding Node of a Binary Tree in a Clone of That Tree](https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/)

```cpp
class Solution {
public:
    TreeNode * ans;
    TreeNode * target;

    void inorder(TreeNode * original, TreeNode * cloned){
        if(original != NULL)
        {
            inorder(original -> left, cloned -> left);
            if(original == target)
            { 
                ans = cloned;
                return;
            }
            inorder(original -> right, cloned -> right);
        }
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        this -> target = target;
        inorder(original, cloned);
        return ans;
    }
};
```
