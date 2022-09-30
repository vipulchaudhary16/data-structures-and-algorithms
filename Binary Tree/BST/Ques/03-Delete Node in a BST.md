# [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/)

```cpp
class Solution {
public:
    int findMin(TreeNode *root)
    {
        if(root == NULL)
            return -1;
        TreeNode * curr = root;
        while(curr -> left != NULL)
            curr = curr -> left;
        return curr -> val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return root;
        
        if(root -> val == key){
            //having no subtree
            if(!root-> left and !root -> right){
                delete root;
                return NULL;
            }
            //having one subtree
                //left subtree
            if(root -> left and !root ->right){
                TreeNode * temp = root -> left;
                delete root;
                return temp;
            }
            
                //right subtree
            if(!root -> left and root ->right){
                TreeNode * temp = root -> right;
                delete root;
                return temp;
            }
            
            //having two subtree
            if(root -> left and root -> right){
                int mini = findMin(root -> right);//find min value from right subtree
                root -> val = mini; //replace keynode with min value
                root -> right = deleteNode(root -> right, mini); //delete min value node
                return root;
                
            }
            
        } else if(key > root -> val){
            root -> right = deleteNode(root -> right, key);
            return root;
        } else {
            root -> left = deleteNode(root -> left, key);
            return root;
        }
        
        return root;
    }
};
```