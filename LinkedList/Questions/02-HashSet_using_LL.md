## [Design HashSet ](https://leetcode.com/problems/design-hashset/) 

```java

class MyHashSet {
    ListNode head;
    
    public MyHashSet() {
        head = null;
    }
    public void add(int key) {
        //we will not add if it contains
        if(contains(key))
            return;
        
        //if adding for first time
        if(head == null){
            head = new ListNode(key);
            return;
        }
        
        ListNode temp = head;
        while(temp.next != null)
            temp = temp.next;
        
        temp.next = new ListNode(key);
    }
    
    public void remove(int key) {
        if(head != null && head.val == key)
        {
            head = head.next;
            return;
        }
        
        ListNode temp = head;
        while(temp != null && temp.next != null)
        {
            if(temp.next.val == key){
                temp.next = temp.next.next;
                return;
            } else {
                temp = temp.next;
            }
        }
    }
    
    public boolean contains(int key) {
        ListNode temp = head;
        
        while(temp != null)
        {
            if(temp.val == key)
                return true;
            temp = temp.next;
        }
        
        return false;
    }
}

class ListNode {
    int val;
    ListNode next;
    public ListNode(){}
    public ListNode(int val) {
        this(val, null);
    }
    public ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
```