### [Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/description/)

```cpp
class Solution {
public:
    void deleteNode(ListNode* node) {
        //Copy value of next node in to current node, which we are called to delete
        node -> val = node -> next -> val;
        //now change link in such a way that we can remove the extra node
        node -> next = node -> next -> next;
        
        //so we deleting the node which are next to our given node, but before deleting we are overriding data of that node into curr node, so it seems that we have deleted given node
        
        /*
        Given : 4 -> 5 -> 1 -> 9 and delete 5 valued node
        step 1:
        4 -> 1 -> 1 -> 9
        step 2:
        4 -> 1 -> 9
        */
    }
};
```