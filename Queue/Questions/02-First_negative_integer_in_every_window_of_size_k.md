## [First negative integer in every window of size k](https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1) 

```cpp
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    deque<long long int> dq;
    vector<long long> ans;

    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
            dq.push_back(i);
    }

    if (dq.size() > 0)
        ans.push_back(A[dq.front()]);
    else
        ans.push_back(0);

    for (int i = K; i < N; i++)
    {
        if (!dq.empty() && (i - dq.front()) >= K)
            dq.pop_front();

        if (A[i] < 0)
            dq.push_back(i);

        if (dq.size() > 0)
            ans.push_back(A[dq.front()]);
        else
            ans.push_back(0);
    }
    return ans;
}
```