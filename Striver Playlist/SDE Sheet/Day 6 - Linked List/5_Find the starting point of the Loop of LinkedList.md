### [Find the starting point of the Loop of LinkedList](https://leetcode.com/problems/linked-list-cycle-ii/)

```cpp

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head -> next) return NULL;

        ListNode *slow = head, *fast = head, *start = head;

        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                while(start != slow){
                    start = start->next;
                    slow = slow->next;
                }
                return slow;
            }
        }

        return NULL;
    }
};