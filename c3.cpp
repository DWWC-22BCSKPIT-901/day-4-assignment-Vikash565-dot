#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inputStack;
    stack<int> outputStack;

    void transferElements() {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        if (outputStack.empty()) {
            transferElements();
        }
        int front = outputStack.top();
        outputStack.pop();
        return front;
    }

    int peek() {
        if (outputStack.empty()) {
            transferElements();
        }
        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};
