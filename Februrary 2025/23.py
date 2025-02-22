class Solution:
    # Function to find the next greater element for each element of the array.
    def nextLargerElement(self, arr):
        n = len(arr)
        result = [-1] * n
        stack = []

        for i in range(n):
            while stack and arr[stack[-1]] < arr[i]:
                result[stack.pop()] = arr[i]
            stack.append(i)
        
        return result
