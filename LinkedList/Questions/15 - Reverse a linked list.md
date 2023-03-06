# [Reverse a Linked list](https://leetcode.com/problems/reverse-linked-list/)


 ```
 # Definition for singly-linked list.
 # struct ListNode {
 #     int val;
 #     ListNode *next;
 #     ListNode() : val(0), next(nullptr) {}
 #     ListNode(int x) : val(x), next(nullptr) {}
 #     ListNode(int x, ListNode *next) : val(x), next(next) {}
 # };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL ;
        ListNode* curnt = head;
        ListNode* forward = NULL;
        
        while(curnt != NULL){
            forward = curnt->next;
            curnt->next = prev;
            prev = curnt;
            curnt = forward;
        }
        return prev;
        
        
    }
};
```
