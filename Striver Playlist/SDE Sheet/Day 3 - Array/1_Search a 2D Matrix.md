### [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/description/0)

#### Approach 1: Binary Search on every row

```
- traverse matrix row by row and apply binary search
```

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        for(int i = 0; i < n; i++){
            auto it = lower_bound(matrix[i].begin(), matrix[i].end(), target);
            if (it != matrix[i].end() && *it == target)
                return true;
        }

        return false;
    }
};
```

#### Approach 2: Greedy type approach.

```
loop ---
- start from top right corner
- if current > target
    - move left
- if current < target
    - move right
- if current == target
    - return true
end ---
return false
```

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        int i = 0, j = m-1;
        int curr;
        while(i < n and j >= 0){
            curr = matrix[i][j];
            if(curr == target) return true;
            if(curr > target) j--;
            else i++;
        }
        return false;
    }
};
```

### Approach 3 : if first element of current row is less that last element of previous row

```
take whole matix as an 1d array
low = 0;
high = (row*col)-1;
do binary search
here everytime index will be
    i = mid/col
    j = mid%col;

as we are assuming the 2d array as 1d so.
```

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        int low = 0, high = (n*m)-1;

        while(low <= high){
            int mid = (low + high)/2;
            int i = mid/m, j = mid%m;

            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) high = mid-1;
            else low = mid+1;
        }

        return false;
    }
};
```
