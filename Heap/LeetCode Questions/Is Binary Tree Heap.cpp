//Is Binary Tree Heap(https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1)

class Solution {
  public:
    int countNodes(struct Node* tree){
        if(!tree) return 0;
        return 1 + countNodes(tree->left) + countNodes(tree->right);
    }
    
    bool isCBT(struct Node * root, int i, int count){
        if(!root) return true;
        if(i >= count) return false;
        else return (isCBT(root->left, 2*i+1, count) and isCBT(root->right, 2*i+2, count));
    }
    
    bool isMaxHeap(struct Node * root){
        if(!root->left and !root->right) return true;
        if(!root -> right) return root -> data > root -> left -> data;
        else{
            bool left = isMaxHeap(root -> left);
            bool right = isMaxHeap(root -> right);
            return (left and right and root -> data > root -> right -> data and root -> data > root -> left -> data);
        }
    }
    
    bool isHeap(struct Node* tree) {
        int nodes = countNodes(tree);
        return (isCBT(tree, 0, nodes) and isMaxHeap(tree));
    }
};