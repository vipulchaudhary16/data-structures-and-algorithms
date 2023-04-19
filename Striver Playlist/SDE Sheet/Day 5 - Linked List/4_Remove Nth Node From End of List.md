### [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)

```cpp
class Solution {
public:
    int getLen(ListNode * head){
        int n = 0;
        while(head){
            head= head->next;
            n++;
        }
        return n;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLen(head);

        if(n == len) return head->next;
        if(n == 1 and len==1) return NULL;

        int target = len - n;
        ListNode * temp = head;

        while(target > 1 and temp){
            temp = temp->next;
            target--;
        }
        temp->next = temp->next->next;
        
        return head;
    }
};
```

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * res = new ListNode(-1);
        res -> next = head;

        ListNode *p1 = res, *p2 = res;
        for(int i = 0; i < n; i++) p1=p1->next;
        while(p1->next){
            p1=p1->next;
            p2=p2->next;
        }
        
        p2->next = p2->next->next;
        return res->next;
    }
};
```