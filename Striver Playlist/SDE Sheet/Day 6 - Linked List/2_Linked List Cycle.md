### [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * slow = head, * fast = head;

       while(true){
           if(!slow || !fast || !fast -> next) return false;
           slow = slow -> next;
           fast = fast -> next -> next;
           if(slow == fast) return true;
       }

       return false;
    }
};
```
