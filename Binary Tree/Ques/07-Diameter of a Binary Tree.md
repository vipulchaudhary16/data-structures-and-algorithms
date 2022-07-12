# [Diameter of a Binary Tree](https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/)

## Using height concept
```cpp
class Solution {
  public:
    int height(struct Node* node){
        // code here 
        if(node == NULL)
            return 0;
        
        int l_h = height(node -> left);
        int r_h = height(node -> right);
        
        return max(l_h, r_h) + 1;
    }
    
    int diameter(Node* root) {
        if(root == NULL)
            return 0;
        
        int op1 = diameter(root -> left);
        int op2 = diameter(root -> right);
        int op3 = height(root -> left) + height(root -> right) + 1;
        
        return max(op1, max(op2, op3));
    }
};
```
---
## Optimized Approach

```cpp
class Solution {
  public:
  pair<int , int> diameterFast(Node * root){
    if(root == NULL)
        return {0,0};
    
    pair<int, int> left = diameterFast(root -> left);
    pair<int ,int> right = diameterFast(root -> right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    return {max(op1,max(op2, op3)), (max(left.second , right.second)+1)};
}
    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};
```