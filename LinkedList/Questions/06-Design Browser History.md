## [Design Browser History ](https://leetcode.com/problems/design-browser-history/) 

### Doubly LL Approach

```cpp
class Node{
public:
    string url;
    Node* next;
    Node* prev;
    Node(string url){
        this -> url = url;
        next = prev = NULL;
    };
};

class BrowserHistory {
public:
    Node * historyHead;
    
    BrowserHistory(string homepage) {
        historyHead = new Node(homepage);
    }
    
    void visit(string url) {
        Node * temp = new Node(url);
        historyHead -> next = temp;
        temp -> prev = historyHead;
        historyHead = temp;
    }
    
    string back(int steps) {
        while(steps-- and historyHead->prev)
            historyHead = historyHead -> prev;
        
        return historyHead -> url;
    }
    
    string forward(int steps) {
        while(steps-- and historyHead->next)
            historyHead = historyHead -> next;
        
        return historyHead -> url;
    }
};
```

### STL approach

```cpp
class BrowserHistory {
public:
    list<string> history;
    list<string> :: iterator it;
    
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        it = history.begin();
    }
    
    void visit(string url) {
        auto del = it;
        del++;
        history.erase(del, history.end());
        history.push_back(url);
        it++;
    }
    
    string back(int steps) {
        while(it != history.begin() and steps--)
            it--;
        
        return *it;
    }
    
    string forward(int steps) {
        while(it != (--history.end()) and steps--)
            it++;
        
        return *it;
    }
};
```