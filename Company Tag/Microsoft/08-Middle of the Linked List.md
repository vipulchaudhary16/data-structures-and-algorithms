# [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;
        
        while(fast != NULL and fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return slow;
    }
};
```