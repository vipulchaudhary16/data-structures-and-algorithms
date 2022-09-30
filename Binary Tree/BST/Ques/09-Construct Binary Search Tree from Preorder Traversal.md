# [Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)

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

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> pre = preorder;
        sort(preorder.begin(), preorder.end());
        vector<int> in = preorder;
        int preStart = 0;
        setMap(in);
        return solve(in, pre, preStart, 0 , pre.size() - 1);
    }
};
```

```cpp
class Solution {
public:
    TreeNode* solve(vector<int> &pre, int mini, int maxi, int &i){
        if(i >= pre.size()) return NULL;
        if(pre[i] < mini || pre[i] > maxi) return NULL;
        
        TreeNode * root = new TreeNode(pre[i++]);
        root -> left = solve(pre, mini, root -> val, i);
        root -> right = solve(pre, root -> val, maxi, i);
            
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int i = 0;
        return solve(preorder, mini, maxi ,i);
    }
};
```