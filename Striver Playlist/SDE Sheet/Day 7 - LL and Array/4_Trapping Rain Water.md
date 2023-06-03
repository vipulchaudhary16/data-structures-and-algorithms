### [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/description/)

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> preMax(n, 0), sufMax(n,0);
        
        preMax[0] = height[0];
        for(int i = 1; i < n; i++)preMax[i] = max(preMax[i-1], height[i]);

        sufMax[n-1] = height[n-1];
        for(int i = n - 2; i >=0; i--)sufMax[i] = max(sufMax[i+1], height[i]);

        int ans = 0;
        for(int i = 0; i < n; i++) ans += (min(preMax[i], sufMax[i]) - height[i]);
        
        return ans;
    }
};
```

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1, lMax = 0, rMax=0, ans = 0;

        while(l <= r){
            if(height[l] <= height[r]){
                if(height[l] > lMax) lMax = height[l];
                else ans += (lMax - height[l]);
                l++;
            } else {
                if(height[r] > rMax) rMax = height[r];
                else ans += (rMax - height[r]);
                r--;
            }
        }

        return ans;
    }
};
```
