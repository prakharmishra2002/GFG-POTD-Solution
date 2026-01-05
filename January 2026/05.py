class Solution:
    def maxSubarraySum(self, arr, k):
        n = len(arr)
        if n < k or k <= 0:
            return 0  # or raise an error, depending on requirements
        
        # Compute sum of first window of size k
        window_sum = sum(arr[:k])
        max_sum = window_sum
        
        # Slide the window from index k to n
        for i in range(k, n):
            # Add the new element and remove the element going out of window
            window_sum = window_sum + arr[i] - arr[i - k]
            max_sum = max(max_sum, window_sum)
        
        return max_sum
