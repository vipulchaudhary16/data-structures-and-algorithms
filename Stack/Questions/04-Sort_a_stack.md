# [Sort A Stack](https://practice.geeksforgeeks.org/problems/sort-a-stack/1)

```cpp
void SortedStack :: sort()
{
   stack<int> extra_stack;
   
   while(!s.empty()){
       if(extra_stack.empty()){
           extra_stack.push(s.top());
           s.pop();
       } else {
           int top = s.top();
           s.pop();
           
           while(!extra_stack.empty() and top < extra_stack.top()){
               s.push(extra_stack.top());
               extra_stack.pop();
           }
           extra_stack.push(top);
       }
   }
    s = extra_stack;
    return;
}
```
```cpp
void sortedInsert(stack<int> &stack, int num)
{
    if (stack.empty() || (!stack.empty() && stack.top() < num))
    {
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();
    sortedInsert(stack, num);
    stack.push(n);
}

void sortStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    sortedInsert(stack, num);
}
```