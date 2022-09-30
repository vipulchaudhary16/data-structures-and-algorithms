# [Largest BST](https://practice.geeksforgeeks.org/problems/largest-bst/1)

```cpp
class info{
    public:
        int maxi, mini, size;
        bool isBST;
};

info solve(Node * root, int &ans){
    if(!root){
        info temp;
        temp.maxi = INT_MIN;
        temp.mini = INT_MAX;
        temp.size = 0;
        temp.isBST = true;
        return temp;
    }
    
    info left = solve(root -> left, ans);
    info right = solve(root -> right, ans);
    
    info currNode;
    
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root -> data, right.maxi);
    currNode.mini = min(root -> data, left.mini);
    
    if(left.isBST and right.isBST and root -> data > left.maxi and root -> data < right.mini)
    {
        currNode.isBST = true;
    } 
    else 
        currNode.isBST = false;
    
    if(currNode.isBST){
        ans = max(ans, currNode.size);
    }
    
    return currNode;
}

class Solution{
    public:
    int largestBst(Node *root)
    {
        int maxSize = 0;
        solve(root, maxSize);
        return maxSize;
    }
};
```