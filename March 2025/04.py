import bisect

class Solution:
    def lis(self, arr):
        ans = []
        for num in arr:
            idx = bisect.bisect_left(ans, num)
            if idx == len(ans):
                ans.append(num)
            else:
                ans[idx] = num
        return len(ans)
