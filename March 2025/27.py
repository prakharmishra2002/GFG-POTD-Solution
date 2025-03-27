class Solution:
    def minimumPlatform(self, arr, dep):
        arr.sort(); dep.sort()
        i = j = cnt = ans = 0
        n = len(arr)
        while i < n and j < n:
            if arr[i] <= dep[j]:
                cnt += 1; ans = max(ans, cnt); i += 1
            else:
                cnt -= 1; j += 1
        return ans
