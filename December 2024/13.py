class Solution:
    def findMin(self, arr):
        lo, hi = 0, len(arr) - 1
        while lo < hi:
            if arr[lo] < arr[hi]:
                return arr[lo]
            mid = lo + ((hi - lo) // 2)
            if arr[mid] > arr[hi]:
                lo = mid + 1
            else:
                hi = mid
        return arr[lo]