#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r)
{
    int pivotEle = arr[r];
    int pivotPoint = l;

    for(int i = l; i <= r; i++){
        if(arr[i] > pivotEle){
            swap(arr[i], arr[pivotPoint]);
            pivotPoint++;
        }
    }
    swap(arr[pivotPoint], arr[r]);
    return pivotPoint;
}

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

int main()
{
    int arr[] = {1,-1, 0, 8 , -88, -75, 44, 48};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout<<kth_min(arr, 0, size - 1, 3)<<"\n";

    sort(arr , arr + size);
    for(int i = 0; i < size; i++)
        cout<<arr[i]<<" ";

    cout<<"\n"<<arr[size-3];
    return 0;
}