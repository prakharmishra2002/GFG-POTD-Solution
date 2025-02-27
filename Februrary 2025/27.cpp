#include <iostream>
#include <stack>

class Solution {
    std::stack<int> stack;
    std::stack<int> min_stack;

  public:
    Solution() {
        // Constructor initializes the stacks
    }

    // Add an element to the top of Stack
    void push(int x) {
        stack.push(x);
        if (min_stack.empty() || x <= min_stack.top()) {
            min_stack.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if (!stack.empty()) {
            if (stack.top() == min_stack.top()) {
                min_stack.pop();
            }
            stack.pop();
        }
    }

    // Returns top element of the Stack
    int peek() {
        if (!stack.empty()) {
            return stack.top();
        }
        return -1; // or throw an exception if appropriate
    }

    // Finds minimum element of Stack
    int getMin() {
        if (!min_stack.empty()) {
            return min_stack.top();
        }
        return -1; // or throw an exception if appropriate
    }
};
