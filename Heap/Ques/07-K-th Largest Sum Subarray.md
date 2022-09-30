# [K-th Largest Sum Subarray](https://www.codingninjas.com/codestudio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=3)

```cpp
#include<algorithm>
int getKthLargest(vector<int> &arr, int k)
{
    vector<int> sums;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            sums.push_back(sum);
        }
    }
    
    sort(sums.begin(), sums.end());
    return sums[sums.size()-k];
}
```

### Using Heap

```cpp
#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int, vector<int>, greater<int>> min_heap;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            if(min_heap.size() < k) min_heap.push(sum);
            else if(sum > min_heap.top()){
                min_heap.pop(); min_heap.push(sum);
            }
        }
    }
    return min_heap.top();
}
```