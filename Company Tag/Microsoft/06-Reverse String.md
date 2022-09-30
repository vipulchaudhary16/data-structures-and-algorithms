# [Reverse String](https://leetcode.com/problems/reverse-string/)

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> stack;

        for(auto it : s)
            stack.push(it);

        s.clear();

        while(!stack.empty()){
            s.push_back(stack.top());
            stack.pop();
        }        
    }
};
```

```java
class Solution {
    void solve(char[] s, int l, int r){
        if (l >= r)
            return;
        
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        solve(s , l+1 , r-1);
    }
    
    public void reverseString(char[] s) {
        solve(s , 0 , s.length - 1);
    }
}
```