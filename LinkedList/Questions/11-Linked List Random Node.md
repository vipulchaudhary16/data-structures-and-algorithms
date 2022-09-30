# [Linked List Random Node](https://leetcode.com/problems/linked-list-random-node/)

```
So at the time we see random word, we think about rand() function right?
    Yes, We will do the same here!!

'each node must have the same probability of being chosen' this may confuse us but simply this means is do not return one same value for every time, rand() function will take care of.

so first of all we will generate one random integer
but but but!!!!, this number should not be greater than length of our linkedlist, ok?
so we will take care of this by take modulus of our random number by our length (rand() % length)

Finally, We need two things:
    - one is Linked List length
    - second is one random number in range[0, length]
    - now traverse the linked list for random number time and return data of the node
```

```cpp
class Solution {
public:
    int length = 0; //for linked list length
    ListNode * head_node; //while returning random node value we have not given head value so we have to store it
    
    Solution(ListNode* head) {
        //calculating length
        ListNode * temp = head;
        while(temp != NULL){
            length++;
            temp = temp -> next;
        }
        //saving value for head ref
        head_node = head;
    }
    
    int getRandom() {
        //generating random index number which is less than length
        int rand_idx = rand() % length;
        ListNode * temp = head_node;
        //increasing pointer untill we reach random index
        for(int i = 0; i < rand_idx; i++) 
            temp = temp -> next;
        return temp -> val;
    }
};
```