### [Merge two sorted Arrays without extra space](https://leetcode.com/problems/merge-sorted-array/description/)

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;

        while(i >= 0 and j >= 0){
            if(nums1[i] < nums2[j]){
                nums1[k] = nums2[j];
                j--;
            } else {
                nums1[k] = nums1[i];
                i--;
            }
            k--;
        }

        while(j >= 0) nums1[k--] = nums2[j--];
    }
};