# [Reverse A Stack](https://practice.geeksforgeeks.org/problems/reverse-a-stack/1)

```cpp
class Solution{
public:
    vector<int> Reverse(stack<int> St){
        vector<int> ans;
        solve(St, ans);
        return ans;
    }
    
    void solve(stack<int> st, vector<int> &v){
        if(st.empty()) return;
        int num = st.top();
        st.pop();
        v.push_back(num);
        solve(st, v);
    }
};
```

```cpp
void insertAtBottom(stack<int> &s, int element) {
    if(s.empty()) {
        s.push(element);
      	return ;
    }
    
    int num = s.top();
    s.pop();
    
    insertAtBottom(s, element);
    s.push(num);
}

void reverseStack(stack<int> &stack) {
    if(stack.empty()) {
        return ;
    }
    
    int num = stack.top();
    stack.pop();
    
    reverseStack(stack);
    insertAtBottom(stack,num);
}
```