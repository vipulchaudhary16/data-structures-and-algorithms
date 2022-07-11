# [Reverse an Array](https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/)

## 1. Iterative Approach : 

```cpp
void reverseArray(vector<int> &arr){
    int l = 0;
    int r = arr.size() - 1;

    while(l < r){
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}
```

> Time Complexity : **O(n) in actual its O(n/2)**.

> Space Complexity : **O(1)**
---
## 2. Recursive Approach : 

```cpp
void reverseArray_rec(vector<int> &arr, int l, int r){
    if(l>=r)
        return;
    
    swap(arr[l], arr[r]);

    reverseArray_rec(arr, l+1, r-1);
}
```

> Time Complexity : **O(n)** in actual its O(n/2).

> Space Complexity : **O(1)**