### [Boolean Evaluation](https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0)

#### [GFG LINK](https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article)

```cpp
#include <bits/stdc++.h> 
int mod = 1000000007;

long long f(int i, int j, int isTrue, string &exp, vector<vector<vector<long long>>> &dp){
    if(i > j) return 0;
    if(i == j){
        if(isTrue) return exp[i] == 'T';
        else return exp[i] == 'F';
    }
    
    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    
    long long ways = 0;
    for(int ind = i+1; ind <= j-1; ind += 2){
        long long lt = f(i, ind-1, 1, exp, dp);
        long long lf = f(i, ind-1, 0, exp, dp);
        long long rt = f(ind+1, j, 1, exp, dp);
        long long rf = f(ind+1, j, 0, exp,dp);
        
        if(exp[ind] == '&'){
            if(isTrue) ways = (ways + (lt * rt)%mod)%mod; //both should be true
            else ways = (ways + (rt * lf)%mod + (rf * lt)%mod + (rf * lf)%mod)%mod; //any of one is false
        } else if(exp[ind] == '|'){
            if(isTrue) ways = (ways + (lt * rt)%mod + (lt * rf)%mod + (lf * rt)%mod)%mod; //atleast one is true
            else ways = (ways + (rf * lf)%mod)%mod; //both should be false
        } else if(exp[ind] == '^'){
            if(isTrue) ways = (ways + (lf * rt)%mod + (lt * rf)%mod)%mod; //both should be diff
            else ways = (ways + (lt * rt)%mod + (lf * rf)%mod)%mod; //both should be same
        }
    }
    
    return dp[i][j][isTrue] = ways;
}
int evaluateExp(string & exp) {
    int n = exp.size();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long> (2, -1)));
    return f(0, n-1, 1, exp, dp);
}
```