# [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/submissions/)

```cpp
class Solution {
public:
    Node* connect(Node* root){
        if(!root) return root;
        Node * curr = root;
        
        while(curr -> left){
            Node * temp_curr = curr;
            while(curr){
                curr -> left -> next = curr -> right;
                curr -> right -> next = curr -> next ? curr -> next -> left : NULL;
                curr = curr -> next;
            }
            curr = temp_curr -> left;
        }
        return root;
    }
};
```