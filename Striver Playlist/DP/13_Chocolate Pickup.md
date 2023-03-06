### [Chocolate Pickup](https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos)

```Recursion``

```cpp
#include <bits/stdc++.h> 
int f(int i, int jA, int jB, int r, int c, vector<vector<int>> &grid){
    if(jA < 0 or jB < 0 or jA >= c or jB >= c) return -1e8;
    if(i == r - 1){
        return (jA == jB ? grid[i][jA] : (grid[i][jA] + grid[i][jB]));
    }
    
    int maxi = -1e8;
    for(int j1 = -1 ; j1 <= 1; j1++){
        for(int j2 = -1; j2 <= 1; j2++){
            int value = jA == jB ? grid[i][jA] : (grid[i][jA] + grid[i][jB]);
            value += f(i+1, jA + j1, jB + j2, r, c, grid);
            maxi = max(maxi, value);
        }
    }
    
    return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    return f(0, 0, c-1, r, c, grid);
}

/*
TC = O(3^r * 3^r)
SC = O(r)
*/
```

```Recursive DP```

```cpp
#include <bits/stdc++.h> 
int f(int i, int jA, int jB, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    if(jA < 0 or jB < 0 or jA >= c or jB >= c) return -1e8;
    if(i == r - 1) return (jA == jB ? grid[i][jA] : (grid[i][jA] + grid[i][jB]));
    if(dp[i][jA][jB] != -1) return dp[i][jA][jB];
    
    int maxi = -1e8;
    for(int j1 = -1 ; j1 <= 1; j1++){
        for(int j2 = -1; j2 <= 1; j2++){
            int value = (jA == jB ? grid[i][jA] : (grid[i][jA] + grid[i][jB]));
            value += f(i+1, jA + j1, jB + j2, r, c, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][jA][jB] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int> > > dp(r, vector<vector<int>> (c, vector<int>(c, -1)));
    return f(0, 0, c-1, r, c, grid, dp);
}

/*
TC = O(r*c*c) * O(9)
SC = O(r*c*c) + O(r)
*/
```

```Tabulation DP```

```cpp
#include <bits/stdc++.h> 

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int> > > dp(r, vector<vector<int>> (c, vector<int>(c, 0)));
    
    //base case
    for(int j1 = 0; j1 < c; j1++){
        for(int j2 = 0; j2 < c; j2++){
            dp[r-1][j1][j2] = j1 == j2 ? grid[r-1][j2] : grid[r-1][j1] + grid[r-1][j2];
        }
    }
    
    for(int i = r-2; i >= 0; i--){
        for(int jA = 0; jA < c; jA++){
            for(int jB = 0; jB < c; jB++){
                int maxi = -1e8;
                for(int j1 = -1 ; j1 <= 1; j1++){
                    for(int j2 = -1; j2 <= 1; j2++){
                        int value = (jA == jB ? grid[i][jA] : (grid[i][jA] + grid[i][jB]));
                        
                        //if not out of bound case
                        if(jA + j1 < c and jA + j1 >=0 and jB + j2 < c and jB + j2 >= 0)
                            value += dp[i+1][jA + j1][jB + j2];
                        else
                            value += -1e9;
                        maxi = max(maxi, value);
                    }
                }
                dp[i][jA][jB] = maxi;
            }
        }
    }
    
    return dp[0][0][c-1];
}

/*
TC = O(r*c*c) * O(9)
SC = O(r*c*c)
*/
```

```Space Optimization```

```cpp
#include <bits/stdc++.h> 

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<int>> front(c, vector<int>(c, 0));
    vector<vector<int>> curr(c, vector<int>(c, 0));
    //base case
    for(int j1 = 0; j1 < c; j1++){
        for(int j2 = 0; j2 < c; j2++){
            front[j1][j2] = j1 == j2 ? grid[r-1][j2] : grid[r-1][j1] + grid[r-1][j2];
        }
    }
    
    for(int i = r-2; i >= 0; i--){
        for(int jA = 0; jA < c; jA++){
            for(int jB = 0; jB < c; jB++){
                int maxi = -1e8;
                for(int j1 = -1 ; j1 <= 1; j1++){
                    for(int j2 = -1; j2 <= 1; j2++){
                        int value = (jA == jB ? grid[i][jA] : (grid[i][jA] + grid[i][jB]));
                        
                        //if not out of bound case
                        if(jA + j1 < c and jA + j1 >=0 and jB + j2 < c and jB + j2 >= 0)
                            value += front[jA + j1][jB + j2];
                        else
                            value += -1e9;
                        maxi = max(maxi, value);
                    }
                }
                curr[jA][jB] = maxi;
            }
        }
        front = curr;
    }
    
    return front[0][c-1];
}
/*
TC = O(r*c*c) * O(9)
SC = O(c*c)
*/
```