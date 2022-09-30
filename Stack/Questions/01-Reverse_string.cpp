#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> stack;

        for(auto it : s)
            stack.push(it);

        s.clear();

        while(stack.empty()){
            s.push_back(stack.top());
            stack.pop();
        }        
    }
};

int main()
{
    return 0;
}