# [Move all the negative elements to one side of the array ](https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/)

```cpp
void move_minus_at_begining(int arr[], int n){
        int j = 0;
        for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}
```
# Move all the Positive elements to one side of the array

```cpp
void move_plus_at_begining(int arr[], int n){
        int j = 0;
        for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}
```