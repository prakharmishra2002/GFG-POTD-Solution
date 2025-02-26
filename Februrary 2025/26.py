class Solution:
    def maxOfMins(self, arr):
        n = len(arr)
        
        # Array to store previous smaller elements
        left = [-1] * n
        # Array to store next smaller elements
        right = [n] * n
        
        # Create a stack and fill left array
        stack = []
        for i in range(n):
            while stack and arr[stack[-1]] >= arr[i]:
                stack.pop()
            if stack:
                left[i] = stack[-1]
            stack.append(i)
        
        # Clear the stack and fill right array
        stack = []
        for i in range(n-1, -1, -1):
            while stack and arr[stack[-1]] >= arr[i]:
                stack.pop()
            if stack:
                right[i] = stack[-1]
            stack.append(i)
        
        # Array to store maximum of minimums
        result = [0] * (n + 1)
        
        # Fill the result array
        for i in range(n):
            length = right[i] - left[i] - 1
            result[length] = max(result[length], arr[i])
        
        # Fill the rest of the result array
        for i in range(n-1, 0, -1):
            result[i] = max(result[i], result[i+1])
        
        # Exclude the 0th element and return the result
        return result[1:]
