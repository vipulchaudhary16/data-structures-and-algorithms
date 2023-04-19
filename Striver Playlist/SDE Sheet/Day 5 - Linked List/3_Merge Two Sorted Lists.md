### [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/description/)

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *res;
        if(l1->val > l2->val) swap(l1, l2); //l1 must be pointing to smallest
        res = l1; //l1 is the starting of resultant LL

        while(l1 and l2){
            ListNode * prev = NULL;
            while(l1 and l1->val <= l2->val) {
                prev = l1;
                l1 = l1->next;
            }
            prev->next = l2;
            swap(l1, l2);
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;

        if(list2 == NULL)
            return list1;

        if(list1 -> val < list2 -> val){
            list1 -> next = mergeTwoLists(list1 -> next, list2);
            return list1;
        } else {
            list2 -> next = mergeTwoLists(list1, list2 -> next);
            return list2;
        }

    }
};
```
