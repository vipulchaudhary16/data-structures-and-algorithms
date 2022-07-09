## [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)

```cpp
class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root != NULL)
        {
            inorderTraversal(root -> left);
            ans.push_back(root -> val);
            inorderTraversal(root -> right);
        }
        return ans;
    }
};
```

## [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)

```cpp
class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root != NULL)
        {
          ans.push_back(root -> val);
            preorderTraversal(root -> left);
            preorderTraversal(root -> right);
        }
        
        return ans;
    }
};
```


## [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)

```cpp
class Solution {
public:
    vector<int> ans;
    
    vector<int> postorderTraversal(TreeNode* root) {
        if(root != NULL) {
            postorderTraversal(root -> left);
            postorderTraversal(root -> right);
            ans.push_back(root -> val);
        }
        return ans;
    }
};
```