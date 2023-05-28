### [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)

```cpp
class Solution {
public:
    ListNode * reverse(ListNode * ptr) {
        ListNode* pre=NULL;
        ListNode* nex=NULL;
        
        while(ptr!=NULL) {
            nex = ptr->next;
            ptr->next = pre;
            pre=ptr;
            ptr=nex;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL) return true;

        //getting the middle
        ListNode * slow = head, * fast = head;
        while(fast->next and fast -> next -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        //slow is middle
        slow -> next = reverse(slow -> next);

        //comparing        
        ListNode * h1 = head, *h2 = slow -> next;
        while(h2){
            if(h1 -> val != h2 -> val) return false;
            h1 = h1 -> next;
            h2 = h2 -> next;
        }

        return true;
    }
};
```