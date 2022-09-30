# Stack

* Stack is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).
#

### Here is Implementation code in C++
<p></p>

## Class Implementation

```cpp
#include<iostream>
using namespace std;

class Stack{
    int *arr;
    int top;
    int capacity;
    public:
        Stack(int capacity){
            this->top = -1;
            this->capacity = capacity;
            this->arr = (int *)malloc(sizeof(int) * capacity);
        }
```

## Check wheather stack is Full or Empty
```cpp
    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top+1 == capacity;
    }
```

## To add data into stack
```cpp
    void push(int data){
        if(isFull()){
            cout<<"stack overflow: "<<endl;
            return;
        } else {
            arr[++top] = data;
        }
    }
```
## To remove top element from stack
```cpp 
    int pop(){
        if(isEmpty()){
            cout<<"stack underflow: "<<endl;
            return -1;
        }
        return arr[top--];
    }
```
## Driver Code
```cpp
int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.print_stack();
    return 0;
}
```