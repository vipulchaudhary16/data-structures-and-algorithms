# [Sum Tree](https://practice.geeksforgeeks.org/problems/sum-tree/)

```cpp
class Solution
{
    public:
    pair<bool, int> isSumTree_fast(Node * root){
        if(root == NULL)
            return {true, 0};
        
        if(root -> left == NULL and root -> right == NULL)
            return {true, root -> data};
            
        pair<bool, int> leftAns = isSumTree_fast(root -> left);
        pair<bool, int> rightAns = isSumTree_fast(root -> right);
        
        return {leftAns.first && rightAns.first && (root -> data == leftAns.second + rightAns.second),
                2 * root -> data};
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         isSumTree_fast(root).first;
    }
};
```