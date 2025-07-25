  class Solution:
    def maxCircularSum(self, arr):
        def kadane(nums):
            max_current = max_global = nums[0]
            for num in nums[1:]:
                max_current = max(num, max_current + num)
                max_global = max(max_global, max_current)
            return max_global

        total_sum = sum(arr)
        max_kadane = kadane(arr)  # Case 1: non-wrapping
        min_kadane = kadane([-x for x in arr])  # Case 2: wrapping

        # If all elements are negative, return max_kadane
        if total_sum + min_kadane == 0:
            return max_kadane
        
        return max(max_kadane, total_sum + min_kadane)
