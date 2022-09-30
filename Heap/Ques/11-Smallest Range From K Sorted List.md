# [Smallest Range From K Sorted List](https://www.codingninjas.com/codestudio/problems/smallest-range-from-k-sorted-list_1069356?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar)

```cpp
#include<queue>
#include<limits.h>
class node{
    public:
        int data, row, col;
        node(int data, int row, int col){
            this-> data = data;
            this -> col = col;
            this -> row = row;
        }
};

class compare{
    public:
    bool operator()(node * a, node * b){
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node *, vector<node *>, compare> pq;
    
    for(int i = 0; i < k; i++){
        int ele = a[i][0];
        mini = min(mini, ele);
        maxi = max(maxi, ele);
        pq.push(new node(ele, i, 0));
    }
    
    int start = mini, end = maxi;
    
    while(!pq.empty()){
        auto top = pq.top(); pq.pop();
        int mini = top->data;
        if(maxi - mini < end - start){
            end = maxi;
            start = mini;
        }
        
        if(top -> col + 1< n){
            maxi = max(maxi, a[top -> row][top -> col + 1]);
            pq.push(new node(a[top -> row][top -> col + 1], top -> row, top -> col + 1));
        }
        else break;
    }
    
    return end - start + 1;
    
}
```

# [Smallest Range Covering Elements from K Lists](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/)

```cpp
class Solution {
public:
class node{
    public:
        int data, row, col;
        node(int data, int row, int col){
            this-> data = data;
            this -> col = col;
            this -> row = row;
        }
};

class compare{
    public:
    bool operator()(node * a, node * b){
        return a->data > b->data;
    }
};
    
vector<int> smallestRange(vector<vector<int>>& nums) {
    int mini = INT_MAX;
    int maxi = INT_MIN;
    priority_queue<node *, vector<node *>, compare> minHeap;

    int n = nums.size();

    //finding min and max for first column
    for(int i = 0; i < n; i++){
        int ele = nums[i][0];
        mini = min(mini, ele);
        maxi = max(maxi, ele);
        minHeap.push(new node(ele, i, 0));
    }

    //initial range 
    int start = mini, end = maxi;

    while(!minHeap.empty()){
        auto curr = minHeap.top();
        minHeap.pop();
        
        if(curr -> col + 1 < nums[curr -> row].size()){
            int r = curr -> row;
            int c = curr -> col + 1;
            minHeap.push(new node(nums[r][c], r, c));
            
            mini = minHeap.top()->data;
            maxi = max(maxi, nums[r][c]);
            
            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }
        } 
        else break;
    }

    return {start, end};
}
};
```