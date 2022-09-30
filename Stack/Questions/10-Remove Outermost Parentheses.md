## [Remove Outermost Parentheses ](https://leetcode.com/problems/remove-outermost-parentheses/) 

```cpp
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> stack;
        string ans = "";
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                if(!stack.empty())
                    ans += s[i];
                stack.push(s[i]);
            } else {
                stack.pop();
                if(!stack.empty())
                    ans += s[i];
            }
        }
        
        return ans;
    }
};
```