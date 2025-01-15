class Solution:
    def longestSubarray(self, arr, k):
        mp, sum, res = {}, 0, 0
        for i, num in enumerate(arr):
            sum += num
            if sum == k:
                res = i + 1
            if sum - k in mp:
                res = max(res, i - mp[sum - k])
            mp.setdefault(sum, i)
        return res
