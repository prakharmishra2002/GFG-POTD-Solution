class Solution:
    def maxLen(self, arr):
        hmap = {}
        sum, max_len = 0, 0
        for i in range(len(arr)):
            sum += -1 if arr[i] == 0 else 1
            if sum == 0:
                max_len = i + 1
            elif sum in hmap:
                max_len = max(max_len, i - hmap[sum])
            else:
                hmap[sum] = i
        return max_len
