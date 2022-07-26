# [Minimum element in BST](https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1)

```cpp
int minValue(Node* root) {
    if(root == NULL)
        return -1;
    Node * curr = root;
    while(curr -> left != NULL)
        curr = curr -> left;
    return curr->data;
}
```