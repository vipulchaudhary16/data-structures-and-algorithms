# [Count Negative Numbers in a Sorted Matrix](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/)

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int count = 0;
        for(int i = row - 1; i >= 0; i--){
            for(int j = col - 1; j >= 0; j--){
                if(grid[i][j] < 0)
                    count++;
                else break;
                
            }
        }
        return count;
    }
};
```

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int i = row - 1;
        int j = 0;
        int count = 0;
        
        while(i >= 0 and j < col){
            if(grid[i][j] < 0){
                count += (col - j);
                i--;
                continue;
            }
            j++;
        }
        
        return count;
    }
};
```