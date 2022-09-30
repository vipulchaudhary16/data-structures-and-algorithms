# [Predecessor And Successor In BST](https://www.codingninjas.com/codestudio/problems/_893049?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0)

```cpp
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    BinaryTreeNode<int>* temp = root;
    int pred = -1;
    int succ = -1;
    
    while(temp -> data != key){
        if(temp -> data > key){
            succ = temp -> data;
            temp = temp -> left;
        } else {
            pred = temp -> data;
            temp = temp -> right;
        }
    }
    
    BinaryTreeNode<int>* left = temp -> left;
    while(left){
        pred = left -> data;
        left = left -> right;
    }
    
    BinaryTreeNode<int>* right = temp -> right;
    while(right){
        succ = right -> data;
        right = right -> left;
    }
    
    return {pred, succ};
}
```