# [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

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
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderStorage;
        inorder(root, inorderStorage);
        int i = 0, j = inorderStorage.size()-1;
        
        while(i < j){
            int currSum = inorderStorage[i] + inorderStorage[j];
            if(currSum == k) return true;
            else if(currSum > k) j--;
            else i++;
        }
        return false;
    }
};
```