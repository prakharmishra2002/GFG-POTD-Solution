class Solution:
    def peakElement(self, arr):
        low, high = 0, len(arr) - 1

        while low < high:
            mid = low + (high - low) // 2
            if arr[mid] > arr[mid + 1]:
                high = mid
            else:
                low = mid + 1
        
        return low  