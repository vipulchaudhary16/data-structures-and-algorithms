## [Min Stack](https://leetcode.com/problems/min-stack/) 

```cpp
class MinStack {
private:
    stack<pair<int,int>> st;
    
public:    
    MinStack() {}
    
    void push(int val) {
		if(st.empty() || val < st.top().second){
			st.push({val,val});
		}
        else {
            st.push({val,st.top().second});
		}
	}
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
```
