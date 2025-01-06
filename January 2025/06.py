class Solution:
    def sumClosest(self, arr, target):
        arr.sort()
        l, r, minDiff, res = 0, len(arr) - 1, float('inf'), []
        while l < r:
            s = arr[l] + arr[r]
            if abs(target - s) < minDiff:
                minDiff, res = abs(target - s), [arr[l], arr[r]]
            l += s < target
            r -= s >= target
        return res
