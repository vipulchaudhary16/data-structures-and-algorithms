## [Reverse First K elements of Queue ](https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1/) 

```cpp
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;
    int temp_k = k;
    
    while(k--){
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    
    int temp = q.size() - temp_k;
    while(temp--){
        q.push(q.front());
        q.pop();
    }
    
    return q;
}
```
