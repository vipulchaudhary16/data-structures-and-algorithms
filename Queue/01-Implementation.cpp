#include<bits/stdc++.h>
using namespace std;

class Queue{
    int size;
    int * arr;
    int rear, front;

    public:
        Queue(){
            size = 100001;
            arr = new int[size];
            rear = 0;
            front = 0;
        }

        bool isEmpty(){
            return rear == front;
        }

        bool isFull(){
            return rear == size;
        }

        void enqueue(int data){
            if(isFull()){
                cout<<"Queue is full\n";
            } else {
                arr[rear++] = data; 
            }
        }

        int dequeue(){
            if(isEmpty()){
                cout<<"Queue is empty\n";
                return -1;
            } else {
                int ret = arr[front];
                arr[front] = -1;
                front++;
                return ret;
            }
        }

        int Getfront(){
            return (front != rear ? arr[front] : -1);
        }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    cout<<q.Getfront()<<"\n";
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<q.Getfront()<<"\n";
    
    return 0;
}