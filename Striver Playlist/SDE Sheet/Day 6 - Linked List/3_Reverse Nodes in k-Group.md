### [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/description/)

```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL) return head;
        
        int len = 0;
        ListNode * temp = head;
        while(temp) len++, temp = temp -> next;

        ListNode * start = new ListNode(-1);
        start -> next = head;

        ListNode * pre = start, * curr, * next;

        while(len >= k){
            curr = pre -> next;
            next = curr -> next;
            for(int i = 1; i < k; i++){
                curr -> next = next -> next;
                next -> next = pre -> next;
                pre -> next = next;
                next = curr -> next;
            }
            pre = curr;
            len -= k;
        }
        return start -> next;
    }
};
```