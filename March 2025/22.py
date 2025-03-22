class Solution:
    def maxValue(self, nums):
        if len(nums) == 1:
            return nums[0]

        def rob(l, r):
            prev2 = prev1 = 0
            for i in range(l, r + 1):
                prev2, prev1 = prev1, max(prev1, prev2 + nums[i])
            return prev1

        return max(rob(0, len(nums) - 2), rob(1, len(nums) - 1))
