### [Unique Paths II](https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0)

```cpp
int mod = (int) (1e9+7);

int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(i == 0 and j == 0) return 1;
    if(i < 0 or j < 0) return 0;
    if(mat[i][j] == -1) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int up = solve(i-1,j,mat,dp);
    int left = solve(i, j-1, mat, dp);
    
    return dp[i][j] = (up+left)%mod;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n, vector<int>(m,-1));
    return solve(n-1, m-1, mat, dp);
}
```