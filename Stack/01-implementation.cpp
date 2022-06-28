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

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top+1 == capacity;
    }

    void push(int data){
        if(isFull()){
            cout<<"stack overflow: "<<endl;
            return;
        } else {
            arr[++top] = data;
        }
    }

    int pop(){
        if(isEmpty()){
            cout<<"stack underflow: "<<endl;
            return -1;
        }
        return arr[top--];
    }

    void print_stack(){
    for (int i = 0; i<=top; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
};



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