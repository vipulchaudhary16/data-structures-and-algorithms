# [ Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/)

```cpp
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode * even = head -> next;
        ListNode * odd = head;
        ListNode * evenHead = even;
        
        while(even != NULL and even -> next != NULL){
            odd -> next = even -> next;
            odd = odd -> next;
            even -> next = odd -> next;
            even = even -> next;
        }
        
        odd -> next = evenHead;
        
        return head;
    }
};
```