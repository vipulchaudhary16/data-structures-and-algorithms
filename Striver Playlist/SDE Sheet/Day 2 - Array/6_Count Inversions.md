### [Count Inversions](https://www.codingninjas.com/codestudio/problems/count-inversions_615?leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 

void merge(long long * arr, long long temp[], int left, int mid, int right, int &ans){
    int i = left;
    int j = mid;
    int k = left;
    while((i <= mid-1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            ans = ans + (mid - i);
        }
    }

    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left ; i <= right ; i++)
        arr[i] = temp[i];
}


void mergeSort(long long * arr, long long temp[], int left, int right, int &ans){
    if(left < right){
        int mid = (right+left)/2;
       mergeSort(arr,temp, left, mid, ans);
       mergeSort(arr,temp, mid+1, right, ans);
       merge(arr, temp , left, mid+1, right, ans);
    }
}
long long getInversions(long long *arr, int n){
    int ans = 0;
    long long  temp[n];
    mergeSort(arr, temp, 0, n-1, ans);
    return ans;
}