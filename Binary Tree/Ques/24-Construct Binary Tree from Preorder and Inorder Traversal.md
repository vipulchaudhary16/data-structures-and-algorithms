# [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

```cpp
class Solution {
public:
    map<int, int> map;
    
    void setMap(vector<int> &arr){
        for(int i = 0; i < arr.size(); i++)
            map[arr[i]] = i;
    }
    
    TreeNode * solve(vector<int> &in, vector<int> &pre, int &idx, int inStart, int inEnd){
        if(idx >= in.size() || inStart > inEnd)
            return NULL;
        
        int rootEle = pre[idx++];
        TreeNode * root = new TreeNode(rootEle);
        int pos = map[rootEle];
        
        //recursive calls
        root -> left = solve(in, pre, idx, inStart, pos - 1);
        root -> right = solve(in, pre, idx, pos + 1, inEnd);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int preStart = 0;
        setMap(in);
        return solve(in, pre, preStart, 0, pre.size()-1);
    }
};

```