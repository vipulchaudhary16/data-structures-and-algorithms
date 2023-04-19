### [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/description/)

Observations:
* Every row has i+1 elements where i is range from 0 to numRows
* for every row, the first and last element is 1
* remaining elements are sum of the elements above it and above it's left element


```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pasTri(numRows);

        for(int i = 0; i < numRows; i++){
            pasTri[i].resize(i+1);
            pasTri[i][0]=1;
            pasTri[i][i]=1;

            for(int j = 1; j < i; j++)
                pasTri[i][j] = pasTri[i-1][j] + pasTri[i-1][j-1];
        }

        return pasTri;
        /*
        TC : O(numRows^2)
        SC : O(numRows^2)
        */
    }
};
```