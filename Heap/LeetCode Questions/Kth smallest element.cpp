//(Kth smallest Element) https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
       priority_queue<int> pq;
       
       for(int i = 0; i < k; i++){
           pq.push(arr[i]);
       }
       
       for(int i = k; i <= r; i++){
           if(arr[i] < pq.top()){
               pq.pop();
               pq.push(arr[i]);
           }
       }
       
       return pq.top();
    }
};