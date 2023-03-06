#include <iostream>
#include<limits.h>
#include<vector>
using namespace std;

int solve(int i, int k, vector<int> height, vector<int> &dp)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int mn = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (i - j >= 0)
        {
            int jump = solve(i - j, k, height, dp) + abs(height[i] - height[i - j]);
            mn = min(jump, mn);
        }
    }
    return dp[i] = mn;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    vector<int> dp(n + 1, -1);
    cout << solve(n - 1, k, h, dp);
    return 0;
}