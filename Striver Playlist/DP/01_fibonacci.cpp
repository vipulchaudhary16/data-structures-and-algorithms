#include <bits/stdc++.h>
using namespace std;

int fibonacci_memo(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibonacci_memo(n - 1, dp) + fibonacci_memo(n - 2, dp);
}

int fibonacci_itr(int n)
{
    vector<int> table(n + 1);
    table[0] = 0;
    table[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        table[i] = table[i - 1] + table[i - 2];
    }
    return table[n];
}

int fibonacci_sc_o1(int n)
{
    int prev1 = 1, prev2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev2 + prev1;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << fibonacci_sc_o1(n);
    return 0;
}