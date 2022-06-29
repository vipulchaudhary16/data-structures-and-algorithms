## [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) 

#

```cpp
class Solution
{
private:
	vector<int> nextSmallerElementIndex(vector<int> arr, int n)
	{
		stack<int> st;
		st.push(-1);
		vector<int> ans(n);

		for (int i = n - 1; i >= 0; i--)
		{
			int curr = arr[i];
			while (st.top() != -1 && arr[st.top()] >= curr)
				st.pop();

			ans[i] = st.top();
			st.push(i);
		}
		return ans;
	}

private:
	vector<int> prevSmallerElementIndex(vector<int> arr, int n)
	{
		stack<int> st;
		st.push(-1);
		vector<int> ans(n);

		for (int i = 0; i < n; i++)
		{
			int curr = arr[i];
			while (st.top() != -1 && arr[st.top()] >= curr)
				st.pop();

			ans[i] = st.top();
			st.push(i);
		}

		return ans;
	}

public:
	int largestRectangleArea(vector<int> &heights)
	{
		int n = heights.size();

		vector<int> next = nextSmallerElementIndex(heights, n);
		vector<int> prev = prevSmallerElementIndex(heights, n);

		int area = INT_MIN;

		for (int i = 0; i < n; i++)
		{
			int l = heights[i];

			if (next[i] == -1)
				next[i] = n;
			int b = next[i] - prev[i] - 1;

			int tempArea = l * b;
			area = max(area, tempArea);
		}

		return area;
	}
};
```