# [Height of Binary Tree](https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1)

```cpp
class Solution{
    public:
    int height(struct Node* node){
        if(node == NULL)
            return 0;
        
        int l_h = height(node -> left);
        int r_h = height(node -> right);
        
        return max(l_h, r_h) + 1;
    }
};
```