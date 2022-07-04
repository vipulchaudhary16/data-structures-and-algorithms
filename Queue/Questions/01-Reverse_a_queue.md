## [Reverse a Queue](https://practice.geeksforgeeks.org/problems/queue-reversal/1) 

### Using Stack

```cpp
queue<int> rev(queue<int> q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    return q;
}
```
#
### Recursive Approach
```cpp
void recRev(queue<int> &q)
{
    if(q.empty())
        return;
    
    int num = q.front();
    q.pop();
    
    recRev(q);
    
    q.push(num);
}

queue<int> rev(queue<int> q)
{
    recRev(q);
    return q;
}
```