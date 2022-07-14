# [Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

```cpp
class Solution {
public:
    map<int, int> map;
    
    void setMap(vector<int> &arr){
        for(int i = 0; i < arr.size(); i++)
            map[arr[i]] = i;
    }
    
    TreeNode * solve(vector<int> &in, vector<int> &post, int &idx, int inStart, int inEnd){
        if(idx >= in.size() || inStart > inEnd)
            return NULL;
        
        int rootEle = post[idx--];
        TreeNode * root = new TreeNode(rootEle);
        int pos = map[rootEle];
        
        //recursive calls
        root -> right = solve(in, post, idx, pos + 1, inEnd);

        root -> left = solve(in, post, idx, inStart, pos - 1);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        setMap(inorder);
        int n = inorder.size();
        int index = n - 1;
        return solve(inorder, postorder, index, 0, n - 1);
    }
};
```