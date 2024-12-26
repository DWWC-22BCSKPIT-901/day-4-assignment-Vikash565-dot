#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
private:
    stack<int> inputStack;
    stack<int> outputStack;

    // Helper function to transfer elements from inputStack to outputStack
    void transferElements() {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }

public:
    // Constructor
    MyQueue() {}

    // Push element to the back of the queue
    void push(int x) {
        inputStack.push(x);
    }

    // Pop the front element from the queue
    int pop() {
        // If outputStack is empty, transfer elements from inputStack
        if (outputStack.empty()) {
            transferElements();
        }
        // Pop and return the top element of outputStack (front of the queue)
        int front = outputStack.top();
        outputStack.pop();
        return front;
    }

    // Return the front element of the queue without removing it
    int peek() {
        // If outputStack is empty, transfer elements from inputStack
        if (outputStack.empty()) {
            transferElements();
        }
        // Return the top element of outputStack (front of the queue)
        return outputStack.top();
    }

    // Return true if the queue is empty, false otherwise
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    MyQueue myQueue;

    // Push elements to the queue
    myQueue.push(1);
    myQueue.push(2);
    
    // Get the front element
    cout << "Front element (peek): " << myQueue.peek() << endl;  // Output: 1

    // Pop the front element
    cout << "Popped element: " << myQueue.pop() << endl;  // Output: 1

    // Check if the queue is empty
    cout << "Is queue empty? " << (myQueue.empty() ? "Yes" : "No") << endl;  // Output: No

    return 0;
}
