# [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

```cpp
class Solution {
public:
    int solve(TreeNode * root, int &i, int k){
        if(!root)
            return -1   ;
        int left = solve(root -> left, i, k);
        if(left != -1)
            return left;
        i++;
        if(k == i)
            return root -> val;
        return solve(root -> right, i, k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        return solve(root, i, k);
    }
};
```

## Iterative Solution Using stack
```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        while(true){
            while(root != NULL){
                st.push(root);
                root = root -> left;
            }
            root = st.top(); st.pop();
            if(--k == 0) return root -> val;
            root = root -> right;
        }
    }
};
```