# User function Template for python3
class Solution:
    def findLength(self, color, radius):
        stack = []

        for i in range(len(color)):
            # If stack is not empty and the top element has the same color & radius, pop it
            if stack and stack[-1] == (color[i], radius[i]):
                stack.pop()
            else:
                stack.append((color[i], radius[i]))

        return len(stack)
