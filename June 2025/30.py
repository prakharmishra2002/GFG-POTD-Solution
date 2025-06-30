class Solution():
    def maxMinHeight(self, arr, k, w):
        n = len(arr)

        def canReach(target):
            water = 0
            diff = [0] * (n + 1)
            curr_add = 0

            for i in range(n):
                curr_add += diff[i]
                effective_height = arr[i] + curr_add

                if effective_height < target:
                    needed = target - effective_height
                    water += needed
                    if water > k:
                        return False
                    curr_add += needed
                    if i + w < len(diff):
                        diff[i + w] -= needed
            return True

        low, high = min(arr), max(arr) + k
        ans = low

        while low <= high:
            mid = (low + high) // 2
            if canReach(mid):
                ans = mid
                low = mid + 1
            else:
                high = mid - 1

        return ans
