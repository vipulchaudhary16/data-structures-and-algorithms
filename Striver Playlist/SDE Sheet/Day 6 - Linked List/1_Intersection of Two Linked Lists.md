### [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/description/)

```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode * d1 = head1, * d2 = head2;

        while(d1 != d2){
            d1 = d1 == NULL ? head2 : d1 -> next;
            d2 = d2 == NULL ? head1 : d2 -> next;
        }

        return d2;
    }
};
```