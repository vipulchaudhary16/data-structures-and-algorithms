# [Sum of the Longest Bloodline of a Tree](https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1)

```cpp
class Solution
{
public:

    void solve(Node * root, int sum, int &maxSum, int len, int &maxLen){
        if(root == NULL)
        {
            if(len > maxLen)
            {
                maxLen = len;
                maxSum = sum;
            } else if(len == maxLen){
                maxSum = max(maxSum, sum);
            }
            return;
        }
        
        sum += root -> data;
        
        solve(root -> left, sum, maxSum, len + 1, maxLen);
        solve(root -> right, sum, maxSum, len + 1, maxLen);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int ans = INT_MIN;
        int maxLen = 0;
        
        solve(root, 0, ans, 0, maxLen);
        
        return ans;
    }
};
```