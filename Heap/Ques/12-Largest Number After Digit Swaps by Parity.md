# [Largest Number After Digit Swaps by Parity](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/)

```cpp
class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> even;
        priority_queue<int> odd;
        
        int x = num;
        while(x){
            int d = x % 10;
            //even
            if(d % 2 == 0){
                even.push(d);
            } else {
            //odd
                odd.push(d);
            }
            x /= 10;
        }
        
        string s = to_string(num);
        int ans = 0;
        
        for(auto c : s){
            if((c - '0')%2 == 0){
                ans = ans * 10 + even.top();
                even.pop();
            } else {
                ans = ans * 10 + odd.top();
                odd.pop();
            }
        }
        return ans;
    }
};
```
