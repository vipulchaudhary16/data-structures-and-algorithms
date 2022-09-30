# [https://www.codingninjas.com/codestudio/problems/build-min-heap_1171167](Build mean heap)

```cpp
void heapify(vector<int> &arr, int n, int i){
    int sm = i;
    int l = 2*i+1;
    int r = 2*i+2;
    
    if(l < n and arr[l] < arr[sm]) sm = l;
    if(r < n and arr[r] < arr[sm]) sm = r;
    if(sm != i){
        swap(arr[i], arr[sm]);
        heapify(arr, n, sm);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    return arr;
}
```