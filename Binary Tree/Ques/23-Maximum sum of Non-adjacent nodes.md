# [Maximum sum of Non-adjacent nodes](https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/)

```cpp
class Solution{
  public:
    pair<int, int> solve(Node * root)
    {
        if(root == NULL)
            return {0,0};
        
        auto left = solve(root -> left);
        auto right = solve(root -> right);
        
        pair<int, int> res;
        
        //including curr node
        res.first = root -> data + left.second + right.second;
        //excluding curr node
        res.second = max(left.first, left.second) + max(right.first, right.second);
        
        return res;
    }
    
    int getMaxSum(Node *root) 
    {
        pair<int, int> ans = solve(root); //first value of pair is sum including curr node and second is excluding curr node
        return max(ans.first, ans.second);
        
    }
};
```