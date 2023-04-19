### [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/)

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ans = new ListNode();
        ListNode * temp = ans;
        int carry = 0;

        while(l1 || l2 || carry){
            int sum = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry; //carry can be 0
            carry = sum / 10;
            ListNode * add = new ListNode(sum % 10);
            temp->next = add;
            temp = temp->next;
        }

        return ans->next;
    }
};
```
