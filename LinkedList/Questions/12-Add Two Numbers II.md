# [Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/)

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        ListNode * temp = l1;
        
        while(temp){
            s1.push(temp->val);
            temp = temp -> next;
        }
        temp = l2;
        while(temp){
            s2.push(temp->val);
            temp = temp -> next;
        }
        int carry = 0;
        vector<int> res;
        while(!s1.empty() and !s2.empty()){
            int n1 = s1.top(); s1.pop();
            int n2 = s2.top(); s2.pop();
            int ans = (carry + (n1+n2))%10;
            res.push_back(ans);
            carry = (carry + (n1+n2))/10;;
        }
        
        while(!s1.empty()){
            int ans = (carry + s1.top()) % 10; 
            carry = (carry + s1.top()) / 10;
            s1.pop();
            res.push_back(ans);
        }
        
        while(!s2.empty()){ 
            int ans = (carry + s2.top()) % 10; 
            carry = (carry + s2.top()) / 10;
            s2.pop();
            res.push_back(ans);
        }
        
        if(carry != 0)
            res.push_back(carry);
        
        ListNode * ans = new ListNode(-1);
        temp = ans;
        for(int i = res.size()-1; i>=0; i--){
            temp -> next = new ListNode(res[i]);
            temp = temp -> next;
        }
            
        return ans -> next;
    }
};
```

## Approach 2 : Faster
```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string n1,n2;
        while(l1){
            n1.push_back(l1 -> val + '0');
            l1 = l1 -> next;
        }
        
        while(l2){
            n2.push_back(l2 -> val + '0');
            l2 = l2 -> next;
        }
        
        int a = n1.size() - 1;
        int b = n2.size() - 1;
        int carry = 0;
        ListNode * res = NULL;
        
        while(a >= 0 || b >= 0 || carry == 1){
            int ans = (a >= 0 ? n1[a--]-'0' : 0)
                        + (b >= 0 ? n2[b--]-'0' : 0)
                        + carry;
            ListNode * temp = new ListNode(ans % 10);
            temp -> next = res;
            res = temp;
            cout<<ans%10<<" ";
            carry = ans / 10;
        }
        
        return res;
    }
};
```

## Optimized first approach based on second approach logic

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        ListNode * temp = l1;
        
        while(temp){
            s1.push(temp->val);
            temp = temp -> next;
        }
        temp = l2;
        while(temp){
            s2.push(temp->val);
            temp = temp -> next;
        }
        
        int carry = 0;
        ListNode * res= NULL;
        
        while(!s1.empty() || !s2.empty() || carry == 1){
            int ans = (s1.empty() ? 0 : s1.top()) + (s2.empty() ? 0 : s2.top()) + carry;
            if(!s1.empty()) s1.pop();
            if(!s2.empty()) s2.pop();
            ListNode * temp = new ListNode(ans % 10);
            temp -> next = res;
            res = temp;
            carry = ans / 10;
        }
        return res;
    }
};
```