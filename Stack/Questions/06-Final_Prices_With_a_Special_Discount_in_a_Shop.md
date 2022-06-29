## [Final Prices With a Special Discount in a Shop](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/) 

#

```cpp
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
       int n = prices.size();
        
        stack<int> st;
        st.push(-1);
        
        vector<int> ans(n);
        
        for(int i = n - 1; i >= 0; i--){
            int curr = prices[i];
            
            while(st.top() > curr)
                st.pop();
            
            if(st.top() == -1)
                ans[i] = curr;
            else 
                ans[i] = curr - st.top();
            
            st.push(curr);
        }
        
        return ans;
    }
};

```