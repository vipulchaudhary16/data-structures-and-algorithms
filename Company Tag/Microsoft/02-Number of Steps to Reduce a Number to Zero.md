# [Number of Steps to Reduce a Number to Zero](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/)

```cpp
class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        
        while(num != 0){
            num = num % 2 == 0 ? num / 2 : num - 1;
            count++;
        }
        
        return c;
    }
};
```

* Tc : O(log n)

---
* Looking at the binary representation of a number:
  * To subtract 1 from an odd number means flipping a 1 to a 0.
  * To divide an even number by 2 means shifting right by one, dropping a 0.
  * After subtracting, you'll always get an even number That means: (the number of steps required) = (the total number of bits used to represent the number) + (the number of 1 bits that are in there).

```cpp
int numberOfSteps (int num) {
  return num == 0 ? 0 : log2(num) + bitset<32>(num).count();
}
```
* There's one subtlety here. log2, when rounded down, actually returns (the number of bits used to represent a number) minus 1. But that's perfect for this, because we don't need to shift the last 0, so that balances out nicely. Also note that since log2(0) is undefined, we do have to handle that case separately.