### [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/description/)

```Brute force approach```
```
We have to assume that all elements are greater than 0

* Traverse the matrix
* If we encounter a 0, then make every element of that row and column, which are != 0, to -1
* Traverse the matrix again
* If we encounter a -1, then make that element to 0
```

```Better Approach```
```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<int> rows(r,-1), cols(c, -1);

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == 0) {
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(rows[i] == 0 or cols[j] == 0) matrix[i][j] = 0;
            }
        }
        /*
        TC = O(r*c) + O(r*c)
        SC = O(r) + O(c)
        */
    }
};
```

```Space Optimization```
```
* Using first row and first column as a flag
* here we need extra flag for col0 because we are using first row as a flag

1 1 1 1
0 0 1 1
1 1 1 1

try this example to understand the code
one time try without using col0 flag
```
```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        bool col0 = true;

        for(int i = 0; i < r; i++){
            if(matrix[i][0] == 0) col0 = false;
            for(int j = 1; j < c; j++){
                if(matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for(int i = r-1; i >= 0; i--){
            for(int j = c-1; j >= 1; j--){
                if(matrix[i][0] == 0 or matrix[0][j] == 0) matrix[i][j] = 0;
            }
            if(col0 == false) matrix[i][0] = 0;
        }
        /*
        TC = O(r*c) + O(r*c)
        SC = O(1)
        */
    }
};
