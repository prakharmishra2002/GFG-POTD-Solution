class Solution:
    def calculateSpan(self, arr):
        # Initialize a stack and an array to store the spans
        stack = []
        span = [0] * len(arr)

        # Iterate through the list of prices
        for i in range(len(arr)):
            # While stack is not empty and the current price is greater than
            # the price at the index stored at the top of the stack
            while stack and arr[i] >= arr[stack[-1]]:
                stack.pop()
            # If stack is empty, it means the current price is greater than all previous prices
            if not stack:
                span[i] = i + 1
            else:
                # Calculate the span by subtracting the index of the last higher price from the current index
                span[i] = i - stack[-1]
            # Push the current index to the stack
            stack.append(i)

        return span
