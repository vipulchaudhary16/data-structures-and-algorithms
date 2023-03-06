### [Rod cutting problem](https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0)

```Recursive DP```

```cpp
int solve(int ind, int N, vector<int> &price, vector<vector<int>> &dp){
    if(ind == 0){
        return (N * price[0]); //here we have rod lenght of 1
    }
    
    if(dp[ind][N] != -1) return dp[ind][N];
    
    int notTake = solve(ind-1, N, price, dp);
    int take = -1e9;
    if(ind + 1 <= N) take = price[ind] + solve(ind, N - (ind+1), price, dp) ;
    
    return dp[ind][N] = max(take, notTake);
}


int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return solve(n-1, n, price, dp);
}

```

```Tabulation DP```

```cpp
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n, vector<int>(n+1, 0));
    for(int i = 1; i <= n; i++){
        dp[0][i] = i * price[0];
    }
    
    for(int ind = 1; ind < n; ind++){
        for(int N = 1; N <= n; N++){
            int notTake = dp[ind-1][N];
            int take = -1e9;
            if(ind + 1 <= N) take = price[ind] + dp[ind][N - (ind+1)];

            dp[ind][N] = max(take, notTake);
        }
    }
    
    return dp[n-1][n];
}

```

```Space optimization```

```cpp
int cutRod(vector<int> &price, int n)
{
	vector<int> prev(n+1, 0), curr(n+1, 0);
    for(int i = 1; i <= n; i++){
        prev[i] = i * price[0];
    }
    
    for(int ind = 1; ind < n; ind++){
        for(int N = 1; N <= n; N++){
            int notTake = prev[N];
            int take = -1e9;
            if(ind + 1 <= N) take = price[ind] + curr[N - (ind+1)];

            curr[N] = max(take, notTake);
        }
        prev = curr;
    }
    
    return prev[n];
}

```