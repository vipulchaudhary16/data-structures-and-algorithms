# [Balance a Binary Search Tree](https://leetcode.com/problems/balance-a-binary-search-tree/)

```cpp
class Solution {
public:
    void inorder(TreeNode * root, vector<int> &v){
        if(root){
            inorder(root -> left, v);
            v.push_back(root -> val);
            inorder(root -> right, v);
        }
    }
    
    TreeNode * inToBST(int start, int end, vector<int> inorder){
        if(start > end) return NULL;
        
        int mid = (start + end)/2;
        TreeNode * root = new TreeNode(inorder[mid]);
        
        root -> left = inToBST(start, mid - 1, inorder);
        root -> right = inToBST(mid + 1, end, inorder);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root, in);
        return inToBST(0, in.size()-1, in);
    }
};
```