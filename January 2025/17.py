class Solution:
    def productExceptSelf(self, arr):
        n = len(arr)
        if n == 0:
            return []
        
        # Initialize the result array with 1s
        res = [1] * n
        
        # Calculate left products
        left_product = 1
        for i in range(n):
            res[i] = left_product
            left_product *= arr[i]
        
        # Calculate right products and multiply with left products
        right_product = 1
        for i in range(n-1, -1, -1):
            res[i] *= right_product
            right_product *= arr[i]
        
        return res
