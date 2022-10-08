# [Median in a stream](https://www.codingninjas.com/codestudio/problems/median-in-a-stream_975268?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar)

```cpp
#include<queue>
int signum(int a, int b){
    if(a > b) return 1;
    else if(a < b) return -1;
    else return 0;
}
void callMedian(int ele, priority_queue<int> &maxHeap, 
               priority_queue<int, vector<int>, greater<int> > &minHeap, 
               int &median)
    {
    switch(signum(maxHeap.size(), minHeap.size())){
        // maxHeap.size() == minHeap.size()
        case 0 : 
        if(ele > median){
            minHeap.push(ele);
            median = minHeap.top();
        } else {
            maxHeap.push(ele);
            median = maxHeap.top();
        }
        break;
        
        // maxHeap.size() > minHeap.size()
        case 1 : 
        if(ele > median){
            minHeap.push(ele);
        } else {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(ele);
        }
        median = (minHeap.top() + maxHeap.top())/2;
        break;
        
        // maxHeap.size() < minHeap.size()
        case -1: 
        if(ele > median){
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(ele);
        } else {
            maxHeap.push(ele);
        }
        median = (minHeap.top() + maxHeap.top())/2;
        break;
    }
}

vector<int> findMedian(vector<int> &arr, int n){
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int median = 0;
    for(int i = 0; i < n; i++){
        callMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}

```