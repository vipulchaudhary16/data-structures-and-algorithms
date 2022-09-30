# [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root -> left),maxDepth(root -> right)) + 1;
    }
};
```

## Iterative
```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode *> q;
        q.push(root);
        int h = 0;
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                TreeNode * front = q.front(); q.pop();
                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);
            }
            h++;
        }
        
        return h;
    }
};
```