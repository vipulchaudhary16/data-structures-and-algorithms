#include <bits/stdc++.h>

using namespace std;

void solve(string digits, string output, int index, vector<string> &ans, string mapping[])
{
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }

    int n = digits[index] - '0';
    string value = mapping[n];
    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solve(digits, output, index + 1, ans, mapping);
        output.pop_back();
    }
}

vector<string> phoneKey(string digits)
{
    vector<string> ans;
    if (digits.length() == 0)
    {
        return ans;
    }

    string output;
    int index = 0;
    string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, output, index, ans, mapping);
    return ans;
}

int main()
{

    string digits = {"45"};
    vector<string> ans = phoneKey(digits);
    for (string x : ans)
    {

        for (char i : x)
        {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}