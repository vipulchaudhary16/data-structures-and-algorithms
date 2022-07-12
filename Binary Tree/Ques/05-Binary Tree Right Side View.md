## [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)

```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> q;
        vector<int> ans;
        
        if(root==NULL)
            return ans;
        
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode * curr = q.front();
                q.pop();
                
                if(i == size - 1)
                    ans.push_back(curr -> val);
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return ans;
    }
};
```

## Recursive

```cpp
class Solution {
public:
    void solve(TreeNode * root, vector<int> &ans, int lvl){
        if(root == NULL)
            return;
        
        if(lvl == ans.size()) //meaning that You have entered a new level
            ans.push_back(root -> val);
        
        solve(root -> right, ans, lvl+1);
        solve(root -> left, ans, lvl+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};
```
