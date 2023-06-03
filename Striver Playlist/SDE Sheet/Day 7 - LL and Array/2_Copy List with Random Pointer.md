### [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/)

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;

        Node * iter = head;
        //step 1
        Node * temp;
        while(iter){
            temp = iter->next;
            iter->next = new Node(iter->val); //adding duplicate 
            iter->next->next = temp; //making connection between added duplicate and next of iter
            iter = temp;
        }

        iter = head; //setting to start node
        //step 2: assigning random pointer
        while(iter){
            if(iter->next){
                iter->next->random = iter->random ? iter->random->next: NULL;
            }
            iter = iter->next ? iter->next->next : NULL;
        }

        //step 3: removing extra connections
        Node * original = head;
        Node * copy = head->next;
        Node * ans = copy; //saving head of answer to return

        while(original and copy){
            original->next = original->next ? original->next->next : NULL;
            copy->next = copy->next ? copy->next->next: NULL;
            original = original->next;
            copy = copy->next;
        }

        return ans;
    }
};
```
