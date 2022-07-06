## [ Remove Duplicates from Sorted List ](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * temp = head;
        
        while(temp != NULL)
        {
            if(temp -> next != NULL and temp -> val == temp -> next - >val and temp -> next -> next != NULL)
            {
                temp->next = temp->next->next;
            } else if(temp -> next != NULL and temp -> next -> next == NULL and temp -> val == temp -> next -> val){
                temp -> next = NULL;
            } else {
                temp = temp -> next;
            }
        }
        
        return head;
    }
};
```
