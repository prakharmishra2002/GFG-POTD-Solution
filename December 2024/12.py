class Solution:
    def countFreq(self, arr, target):
        import bisect
        lower = bisect.bisect_left(arr, target)
        upper = bisect.bisect_right(arr, target)
        return (upper - lower) if lower < len(arr) and arr[lower] == target else 0