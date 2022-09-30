# [Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/)

## Recursive
```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            root = new TreeNode(val);
            return root;
        }
        
        if(val > root -> val)
            root -> right = insertIntoBST(root -> right, val);
        else
            root -> left = insertIntoBST(root -> left, val);
        
        return root;
    }
};
```

## Itrerative
```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * prev , * curr = root;
        TreeNode * newNode = new TreeNode(val);
        
        if(!root) return newNode;
        
        while(curr)
        {
            if(val > curr -> val){
                prev = curr;
                curr = curr -> right;
            } else {
                prev = curr;
                curr = curr -> left;
            }
        }
        
        if(val > prev -> val)
            prev -> right = newNode;
        else
            prev -> left = newNode;   
        
        return root;
    }
};
```