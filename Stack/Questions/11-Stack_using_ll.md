# [Stack using Linked List](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380936?leftPanelTab=0)

```cpp
class Stack
{
    Node * top;
    int size = 0;

public:
    Stack()
    {
        top = NULL;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(int data)
    {
        Node * temp = new Node(data);
        if(top)
            temp -> next = top;
        top = temp;
        size++;
    }

    void pop()
    {
        if(top){
            Node * temp = top;
            top = top -> next;
            free(temp);
            size--;
        }
    }

    int getTop()
    {
       if(top) return top -> data;
       return -1;
    }
};
```