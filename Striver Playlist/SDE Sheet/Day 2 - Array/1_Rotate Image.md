### [Rotate Image](https://leetcode.com/problems/rotate-image/description/)

* rotate 90 degree clockwise
* dry run for 3x3 matrix

```
If we are rotating the matrix 90 degrees clockwise, then the first row becomes the last column, the last column becomes the last row, and so on.
```

```if inplace is not case```
```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> tmp(n, vector<int>(n));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                tmp[j][n-i-1] = matrix[i][j];
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = tmp[i][j];
            }
        }
    }
};
```

```If inplace is case```

```
take transpose of matrix
reverse each row
```

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
        }

        for(int i = 0; i < n; i++) 
            reverse(matrix[i].begin(), matrix[i].end());
    }
};
```