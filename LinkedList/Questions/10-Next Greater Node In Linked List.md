# [Next Greater Node In Linked List](https://leetcode.com/problems/next-greater-node-in-linked-list/)

```cpp
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        
        ListNode * node = head;
        while(node != NULL){
            ListNode * curr = node -> next ? node -> next : NULL;
            while(curr != NULL){
                if(curr -> val > node -> val)
                {
                    result.push_back(curr -> val);
                    break;
                }
                curr = curr -> next;
            }
            if(curr == NULL)
                result.push_back(0);
            node = node -> next;
        }
        
        return result;
    }
};
```

## Optimized using Stack

```cpp
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        //ek map banayenge jisme node apne next greater ko point kar rha hoga
        unordered_map<ListNode *, int> mp; 
        
        //sare node ke liye map me value 0 set karte h pahele to
        for(ListNode * temp = head; temp != NULL; temp = temp -> next)
            mp[temp] = 0;
        
        //ab ek stack bana lenge aur head to push karna hi padega
        stack<ListNode *> s;
        s.push(head);
        //ab sare node ko traverse kar rhe h
        for(ListNode * curr = head -> next; curr != NULL; curr = curr -> next){
            //ab jab tak stack khali na ho jaye tb tak push pop chalta rahege
            /*
            at a time ke liye agar curr node ka value top node ke value se bada h,
            to matlab woh curr node ke liye stack ka top ans ho sakta h
            so woh bhi update karte chalenge
            aur curr ko push to karna hi h
            */
            while(!s.empty() and curr -> val > s.top() -> val){
                mp[s.top()] = curr -> val;
                s.pop();
            }
            s.push(curr);
        }
        
        //ab bas map ko vector me convert karna h
        vector<int> res;
        for(ListNode * tmp = head; tmp != NULL; tmp = tmp -> next){
            res.push_back(mp[tmp]); 
        }
        
        return res;
        
    }
};
```