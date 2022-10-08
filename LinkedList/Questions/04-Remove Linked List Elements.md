## [Remove Linked List Elements ](https://leetcode.com/problems/remove-linked-list-elements/) 

```cpp
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL and head -> val == val)
            head = head -> next;
        
        if(head == NULL)
            return NULL;
        
        ListNode * temp = head;
        
        while(temp != NULL)
        {
            if(temp -> next != NULL and temp -> next -> val == val)
            {
                if(temp -> next -> next != NULL)
                    temp -> next = temp -> next -> next;
                else 
                    temp -> next = NULL;
            } else {
                temp = temp -> next;
            }
        }
        
        return head;
    }
};
```
