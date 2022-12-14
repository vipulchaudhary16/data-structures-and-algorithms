### [Ninja’s Training](https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?leftPanelTab=0)

```Recursion```

```cpp
int f(int day, int last, vector<vector<int>> &points){

    if(day == 0){
        int maxi = 0;
        for(int task = 0; task < 3; task++){
            if(task != last){
                maxi = max(maxi, points[day][task]);
            }
        }
        return maxi;
    }
        
    int ans = 0;
    for(int task = 0; task < 3; task++){
        if(task != last){
            int point = points[day][task] + f(day - 1, task, points);
            ans = max(ans, point);
        }
    }
    
    return ans;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return f(n-1, 3, points);
}

/*
TC : O(2^n *3)
SC : O(n) + O(n*4)
*/
```

```Recursive DP```

```cpp
int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(dp[day][last] != -1) return dp[day][last];

    if(day == 0){
        int maxi = 0;
        for(int task = 0; task < 3; task++){
            if(task != last){
                maxi = max(maxi, points[day][task]);
            }
        }
        return maxi;
    }
        
    int ans = 0;
    for(int task = 0; task < 3; task++){
        if(task != last){
            int point = points[day][task] + f(day - 1, task, points, dp);
            ans = max(ans, point);
        }
    }
    
    return dp[day][last] = ans;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4,-1));
    return f(n-1, 3, points, dp);
}

/*
TC : O(n*3*4)
SC : O(n) + O(n*4)
*/
```

```Tabulation DP```

```cpp
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4,0));
    
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int day = 1; day < n; day++){
        for(int last = 0; last < 4; last++){
            for(int task = 0; task < 3; task++){
                if(task != last)
                {
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    
    return dp[n-1][3];
}

/*
TC : O(n * 3 * 4)
SC : O(n*4)
*/
```


```Space optimization```

```cpp
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> lastDay(4,0);
    
    lastDay[0] = max(points[0][1], points[0][2]);
    lastDay[1] = max(points[0][0], points[0][2]);
    lastDay[2] = max(points[0][0], points[0][1]);
    lastDay[3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int day = 1; day < n; day++){
        vector<int> curr(4,0);

        for(int last = 0; last < 4; last++){
            for(int task = 0; task < 3; task++){
                if(task != last)
                {
                    int point = points[day][task] + lastDay[task];
                    curr[last] = max(curr[last], point);
                }
            }
        }

        lastDay = curr;
    }
    
    return dp[n-1][3];
}

/*
TC : O(n*4*3)
SC : O(4)
*/
```