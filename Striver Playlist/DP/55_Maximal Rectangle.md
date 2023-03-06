### [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)

```cpp
class Solution {
public:
    long long getMaxArea(vector<int> &height, int n)
    {
        stack<long long> st;
        long long ans = 0;
        for(int i = 0; i <= n; i++){
            while(!st.empty() and (i == n or height[st.top()] >= height[i])){
                long long h = height[st.top()];
                st.pop();
                long long width;
                if(st.empty()) width = i;
                else width = (i-st.top()-1);
                ans = max(ans, width * h);
            }
            st.push(i);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<int> height(m);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            int currArea = getMaxArea(height, m);
            ans = max(ans, currArea);
        }
        
        return ans;
    }
};