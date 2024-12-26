#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack; 
    stack<int> minStack;  
public:
    MinStack();
    void push(int val) {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop(); 
        }
        mainStack.pop();
    }
    int top() {
        return mainStack.top();
    }
    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Minimum: " << minStack.getMin() << endl; 
    minStack.pop();
    cout << "Top: " << minStack.top() << endl;       
    cout << "Minimum: " << minStack.getMin() << endl; 
    return 0;
}
