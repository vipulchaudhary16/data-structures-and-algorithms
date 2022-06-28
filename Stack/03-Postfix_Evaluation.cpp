#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
 
// Function to evaluate a given postfix expression
int evalPostfix(string exp)
{
    // create an empty stack
    stack<int> stack;
 
    // traverse the given expression
    for (int i = 0; i < exp.length(); i++)
    {
        // if the current character is an operand, push it into the stack
        if (exp[i] >= '0' && exp[i] <= '9') {
            stack.push(exp[i] - '0');
        }
        // if the current character is an operator
        else {
            // remove the top two elements from the stack
            int x = stack.top();
            stack.pop();
 
            int y = stack.top();
            stack.pop();
 
            // evaluate the expression `x op y`, and push the
            // result back to the stack
            switch (exp[i])
            {
            case '+':
                stack.push(y+x);
                break;
            case '-':
                stack.push(y-x);
                break;
            case '*':
                stack.push(y*x);
                break;
            case '/':
                stack.push(y/x);
                break;
            case '^':
                stack.push(pow(x,y));
                break;
            }
        }
    }
 
    // At this point, the stack is left with only one element, i.e.,
    // expression result
    return stack.top();
}
 
int main()
{
    string exp = "46+2/5*7+";
 
    cout << evalPostfix(exp);
 
    return 0;
}