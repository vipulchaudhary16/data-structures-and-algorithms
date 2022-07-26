* First observe this for row = 5

```
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
```

* Points You may have observed is:
  * starting of every row is 1
  * Ending of every row is 1
  * Every row has column of it's row number, like row number 3 (1 2 1) has 3 column
  * and main point is :
    * for ith element of jth column is sum of it's above element in same column and 1 column before in above row
     
  
* Last point Seems confusing?
```
see for 5th row 3rd element is 6 how does we calculate it?

it is sum of 3 and 3, right?

and what are this 3 on is what it's totally above and one just previous above, got it?

Now let's see code in our favourite language, C++
```

```
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector< vector<int> > result(numRows);
        
        for(int i = 0; i < numRows; i++)
        {
            result[i].resize(i+1);
            result[i][0] = 1;
            result[i][i] = 1;
            
            for(int j = 1; j < i; j++)
                result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
        
        return result;
    }
};
```

* Some points to be understand in code
  * **Why result[i][0] = 1 and result[i][i] = 0** -> Because for every row, value of first and last element is 1.
  * **Why result[i].resize(i + 1)** -> Because see for every row number of column or number of element is equal to it's row number, but we have 0 indexing so add 1 to it.
  
