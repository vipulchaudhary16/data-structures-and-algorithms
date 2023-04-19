### [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * curr = head, * main = NULL;

        while(curr){
            ListNode * remain_part = curr->next;
            curr->next = main;
            main = curr;
            curr = remain_part;
        }
        return main;
    }
};
```