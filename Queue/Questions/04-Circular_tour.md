## [Gas Station](https://leetcode.com/problems/gas-station/) 

```java
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int start = 0, def = 0, bal = 0;
        
        for(int i = 0; i < gas.length; i++)
        {
            bal += (gas[i] - cost[i]);
            
            if(bal < 0)
            {
                start = i + 1;
                def += bal;
                bal = 0;
            }
        }
        
        if(def + bal >= 0)
            return start;
        
        return -1;
        
    }
}
```
