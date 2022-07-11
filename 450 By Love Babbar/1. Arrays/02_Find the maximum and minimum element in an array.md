# [Find the maximum and minimum element in an array](https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/)

## 1. Linear Search Method
```cpp
struct Pair{
    int min, max;
};

Pair find_min_max(int arr[], int n){
    Pair pair = {INT_MAX, INT_MIN};

    for(int i = 0; i < n; i++){
        pair.min = min(pair.min, arr[i]);
        pair.max = max(pair.max, arr[i]);
    }

    return pair;
}
```

> Time Complexity : O(n)

> Space Complexity : O(1)

---
## 2. Divide and Conquer Method
```cpp
struct Pair
{
    int min, max;
};

Pair find_min_max(int arr[], int l, int r){
    Pair ans;

    //if there is only one element
    if(l == r){
        ans.min = arr[l];
        ans.max = arr[l];
        return ans;
    }

    //if there are two elements
    if(l == r + 1){
        ans.min = min(arr[l], arr[r]);
        ans.max = max(arr[l], arr[r]);
        return ans;
    }

    int mid = (l + r)/2;
    Pair  min_max_l, min_max_r;

    //recursively finding minimum and maximum in left and right part of array
    min_max_l = find_min_max(arr, l, mid);
    min_max_r = find_min_max(arr, mid + 1, r);

    //extracting minimum element from both parts
    ans.min = min(min_max_l.min, min_max_r.min);

    //extracting maximum element from both parts
    ans.max = max(min_max_l.max, min_max_r.max);

    return ans;
}
```
>T(n) = 2T(n/2) + 2

* After solving this: **T(n)  = 3n/2 - 2**

> Time Complexity : **O(3n/2 - 2)**

> Space Complexity : **O(1)**