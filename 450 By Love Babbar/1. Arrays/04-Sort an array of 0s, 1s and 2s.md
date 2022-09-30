# [Sort an array of 0s, 1s and 2s](https://leetcode.com/problems/sort-colors/)

```cpp
class Solution {
public:
    void sort_012(vector<int>& a) {
        int lo = 0;
        int hi = a.size() - 1;
        int mid = 0;
  
        while (mid <= hi) {
            switch (a[mid]) {
  
            case 0:
                swap(a[lo++], a[mid++]);
                break;
  
            case 1:
                mid++;
                break;
  
            case 2:
                swap(a[mid], a[hi--]);
                break;
            }
        }
    }
};
```