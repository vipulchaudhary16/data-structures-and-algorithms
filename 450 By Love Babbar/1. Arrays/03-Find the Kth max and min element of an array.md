# Kth Min

## 1. If We are allowed to sort an array

```cpp
int kth_smallest(int arr[], int n, int k)
{
    sort(arr, arr + n);
    return arr[k-1];
}
```

> Time Complexity : **O(nlogn)**.

> Space Complexity : **O(1)**
---

## 2. If We are not allowed to sort ans array

```cpp
int partition(int arr[], int l, int r)
{
    int pivotEle = arr[r];
    int pivotPoint = l;

    for(int i = l; i <= r; i++){
        if(arr[i] < pivotEle){
            swap(arr[i], arr[pivotPoint]);
            pivotPoint++;
        }
    }
    swap(arr[pivotPoint], arr[r]);
    return pivotPoint;
}
```
```cpp
int kth_min(int arr[], int l, int r, int k){
    //if k is invalid
    if(k < 0 and k >= r - l + 1){
        cout<<"Invalid k\n";
        return INT_MAX;
    }
    else 
    {
        int pivot_pos = partition(arr, l,r);

        //we got our answer if
        if(pivot_pos == k - 1)
            return arr[pivot_pos];
        
        if(pivot_pos > k - 1){
            return kth_min(arr, l, pivot_pos - 1, k);
        }
        else {
            return kth_min(arr, pivot_pos + 1, r , k);
        }
    }
}
```
> Time Complexity : **O(n)**.

> Space Complexity : **O(1)**
---
&nbsp;
# Kth Max
## 1. If We are allowed to sort an array

```cpp
int kth_smallest(int arr[], int n, int k)
{
    sort(arr, arr + n);
    return arr[n-k];
}
```

> Time Complexity : **O(nlogn)**.

> Space Complexity : **O(1)**

&nbsp; 

## 2. If We are not allowed to sort ans array

```cpp
int partition(int arr[], int l, int r)
{
    int pivotEle = arr[r];
    int pivotPoint = l;

    for(int i = l; i <= r; i++){
        if(arr[i] > pivotEle){ //The one and only change in above algo for kth Min
            swap(arr[i], arr[pivotPoint]);
            pivotPoint++;
        }
    }
    swap(arr[pivotPoint], arr[r]);
    return pivotPoint;
}
```
```cpp
int kth_max(int arr[], int l, int r, int k){
    //if k is invalid
    if(k < 0 and k >= r - l + 1){
        cout<<"Invalid k\n";
        return INT_MAX;
    }
    else 
    {
        int pivot_pos = partition(arr, l,r);

        //we got our answer if
        if(pivot_pos == k - 1)
            return arr[pivot_pos];
        
        if(pivot_pos > k - 1){
            return kth_max(arr, l, pivot_pos - 1, k);
        }
        else {
            return kth_max(arr, pivot_pos + 1, r , k);
        }
    }
}
```
> Time Complexity : **O(n)**.

> Space Complexity : **O(1)**