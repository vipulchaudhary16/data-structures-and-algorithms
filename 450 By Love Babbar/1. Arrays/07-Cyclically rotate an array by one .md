# [Cyclically rotate an array by one ](https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614)

```cpp
void rotate(int arr[], int n)
{
    int last = arr[n-1];
    
    for(int i = n - 1; i >= 1; i--)
        arr[i] = arr[i-1];
    
    arr[0] = last;
}
```

* ## 2 Pointer Approach

```cpp
void rotate(int arr[], int n){
    int i = 0, j = n  - 1;

    while(i != j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
    }
}
```