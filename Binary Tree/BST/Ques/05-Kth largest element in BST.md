# [Kth largest element in BST](https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1)

```cpp
class Solution
{
    int solve(Node * root, int &i, int k){
        if(!root or i >= k)
            return -1;
        int right = solve(root -> right, i, k);
        if(right != -1)
            return right;
        i++;
        if(i == k)
            return root -> data;
        return solve(root -> left, i , k);
        
    }
    public:
    int kthLargest(Node *root, int K)
    {
        int i = 0;
        return solve(root, i, K);
    }
};
```