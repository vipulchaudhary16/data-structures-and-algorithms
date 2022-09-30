#include <bits/stdc++.h>
using namespace std;

void max_heapify(int A[] , int i , int size){
    int L = 2 * i + 1;
    int R = 2 * i + 2;

    // parent of i will be at i/2 - 1

    int largest;

    // L < size means L is not leaf and A[L] > A[i] means there is bigger number on left side
    if(L < size && A[L] > A[i])
        largest = L;
    else 
        largest = i;
    
    // R < size means R is not leaf and A[R] > A[largest] means there is bigger number on right side
    if(R < size && A[R] > A[largest])
        largest = R;

    //if current element is not largest that means we have to swap and heapify other also
    if(largest != i){
        swap(A[i] , A[largest]);
        max_heapify(A , largest , size);
    }
}

void build_heap(int arr[], int size){
    /*if heap size is N then
        leaves range : n/2 to n-1
        internal node range : 0 to n/2 - 1*/ 
    
    //leaves always follows heap property
    //this is bottom up approach

    for(int i = (size/2)-1 ; i>=0 ; i--)
        max_heapify(arr, i, size);
}

void heap_sort(int arr[], int n){
    build_heap(arr, n);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    heap_sort(arr , n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

}