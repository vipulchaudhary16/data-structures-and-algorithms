//Merge two binary Max heaps(https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1)

class Solution{
    public:
    void heapify(vector<int> &arr, int size, int i){
        int l = 2*i+1;
        int r = 2*i+2;
        int largest = i;
        
        if(l < size and arr[l] > arr[largest])
            largest = l;
        if(r < size and arr[r] > arr[largest])
            largest = r;
        
        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, size, largest);
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        //Merging both array/vectors
        vector<int> ans;
        for(int x : a) ans.push_back(x);
        for(int x : b) ans.push_back(x);
        
        //Building Heap from merged array
        int size = ans.size();
        for(int i = size/2 - 1; i >= 0; i--)
            heapify(ans, size, i);
        
        return ans;
    }
};
