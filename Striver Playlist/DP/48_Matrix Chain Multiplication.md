### [Matrix Chain Multiplication](https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article)

```cpp
class Solution{
public:
    int dp[101][101];
    int f(int i, int j, int arr[]){
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = 1e9;
        for(int k = i; k < j; k++){
            int steps = arr[i-1] * arr[j] * arr[k] + f(i, k, arr) + f(k+1, j, arr);
            mini = min(steps, mini);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof dp);
        return f(1, N-1, arr);
    }
};