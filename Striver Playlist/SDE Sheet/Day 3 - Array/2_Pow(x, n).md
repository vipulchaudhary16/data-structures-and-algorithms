### [Pow(x, n](https://leetcode.com/problems/powx-n/description/)

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if(nn < 0) nn = -1*nn;

        while(nn){
            if(nn%2 == 0){
                x = x * x;
                nn /= 2;
            } else {
                ans *= x;
                nn -= 1;
            }
        }

        if (n < 0) ans = (double)(1.0) / (double)(ans);
        return ans;
    }
    /*
    TC: O(log n)
    */
};
```
