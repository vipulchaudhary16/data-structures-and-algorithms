## [Maximum Twin Sum of a Linked List ](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/) 

```cpp
class Solution {
    ListNode * revLL(ListNode * head)
    {
        ListNode * curr = head;
        ListNode * prev = NULL;
        ListNode * next = NULL;
        
        while(curr != NULL)
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    ListNode * findMid(ListNode* head)
    {
        ListNode * slow = head;
        ListNode * fast = head -> next;
        
        while(fast and fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next ->next;
        }
        
        return slow;
    }
    
public:
    int pairSum(ListNode* head) {
        ListNode * mid = findMid(head);
        mid -> next = revLL(mid -> next);
        
        ListNode * p1 = head;
        ListNode * p2 = mid -> next;
        
        int maxSum = INT_MIN;
        while(p2)
        {
            maxSum = max(maxSum,( p1 -> val + p2 -> val));
            p2 = p2 -> next;
            p1 = p1 -> next;
        }
        
        return maxSum;
    }
};
```
