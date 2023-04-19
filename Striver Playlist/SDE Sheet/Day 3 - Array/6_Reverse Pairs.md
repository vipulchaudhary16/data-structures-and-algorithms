### [Reverse Pairs](https://leetcode.com/problems/reverse-pairs/)

```cpp
class Solution {
public:
    int Merge(vector < int > & nums, int low, int mid, int high) {
        int curr_total = 0;
        int j = mid+1;
        int i = low;
        while(i <= mid){
            while(j <= high and nums[i] > ((long long) 2 * nums[j])) j++;
            curr_total += (j - mid - 1);
            i++;
        }

        vector < int > t;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {

            if (nums[left] <= nums[right]) {
                t.push_back(nums[left++]);
            } else {
                t.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            t.push_back(nums[left++]);
        }
        while (right <= high) {
            t.push_back(nums[right++]);
        }

        for (int i = low; i <= high; i++) {
            nums[i] = t[i - low];
        }
        return curr_total;
    }
    int MergeSort(vector < int > & nums, int low, int high) {

        if (low >= high) return 0;
        int mid = (low + high) / 2;
        int inv = MergeSort(nums, low, mid);
        inv += MergeSort(nums, mid + 1, high);
        inv += Merge(nums, low, mid, high);
        return inv;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return MergeSort(nums, 0, n-1);
    }
};
```