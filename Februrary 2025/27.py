class Solution:

    def __init__(self):
        self.stack = []
        self.min_stack = []

    # Add an element to the top of Stack
    def push(self, x):
        self.stack.append(x)
        if not self.min_stack or x <= self.min_stack[-1]:
            self.min_stack.append(x)

    # Remove the top element from the Stack
    def pop(self):
        if self.stack:
            top = self.stack.pop()
            if top == self.min_stack[-1]:
                self.min_stack.pop()

    # Returns top element of Stack
    def peek(self):
        if self.stack:
            return self.stack[-1]
        return -1

    # Finds minimum element of Stack
    def getMin(self):
        if self.min_stack:
            return self.min_stack[-1]
        return -1
