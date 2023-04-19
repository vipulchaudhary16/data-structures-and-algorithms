### [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/description/)

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * slow = head, * fast = head;

        while(fast && fast->next){
            slow = slow -> next;
            fast = fast->next->next;
        }

        return slow;
    }
};
```
