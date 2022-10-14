#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    if (nums.size() <= index)
    {
        ans.push_back(output);
        return;
    }

    solve(nums, output, index + 1, ans);

    int x = nums[index];
    output.push_back(x);
    solve(nums, output, index + 1, ans);
}

int main()
{

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    for (vector<int> vect1D : ans)
    {
        for (int x : vect1D)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}