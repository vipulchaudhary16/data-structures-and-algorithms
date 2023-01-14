### [Matrix Chain Multiplication](https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article)


```cpp
class Solution{
public:
    int dp[101][101];
    
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, 0, sizeof dp);
        for(int i = N-1; i >= 1; i--){
            for(int j = i+1; j < N; j++){
                int mini = 1e9;
                for(int k = i; k < j; k++){
                    int steps = arr[i-1] * arr[j] * arr[k] + dp[i][k] + dp[k+1][j];
                    mini = min(steps, mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][N-1];
    }
};
```