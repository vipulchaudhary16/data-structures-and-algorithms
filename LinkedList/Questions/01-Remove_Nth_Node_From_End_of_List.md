## [Remove Nth Node From End of List ](https://leetcode.com/problems/remove-nth-node-from-end-of-list) 

```java
class Solution {
    private int getLen(ListNode head)
    {
        int len = 0;
        while(head != null)
        {
            len++;
            head = head.next;
        }
        
        return len;
    }
    public ListNode removeNthFromEnd(ListNode head, int n) {
        //linked list ki length nikalte hue
        int len = getLen(head);
        
        //agar length bhi 1 hai and 1st from last node remove karna h to null kar do head ko
        if(len == 1 && n == 1)
            return null;
        
        //agar length and jisse remove karna h node uska index (from last) same hai to hame 1st node ko remove karna padega to head ka next return kar do
        if(len == n)
            return head.next;
        
        //ab last se nth node remove karna h to starting se woh length - n th index pe hoga
        int count = len - n;
        
        ListNode temp = head;
        //jab tak jiss node ko remove karna h woh node ke pahele wale node pe pointer nahi aaata tab tak temp ko aage chalate jao
        while(count > 1 && temp != null)
        {
            temp = temp.next;
            count--;
        }
        
        //ab hamara temp ke next to uske next ke next se link kar do, kaam ho gya
        temp.next = temp.next.next;
        return head;
    }
}
```
