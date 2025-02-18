class Solution:
    def kLargest(self, arr, k):
        return sorted(arr, reverse=True)[:k]
