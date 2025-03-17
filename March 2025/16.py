class Solution:
    def minJumps(self, arr):
        n, jumps, farthest, end = len(arr), 0, 0, 0
        if n == 1: return 0
        for i in range(n - 1):
            farthest = max(farthest, i + arr[i])
            if i == end:
                jumps += 1
                end = farthest
                if end >= n - 1: return jumps
        return -1
