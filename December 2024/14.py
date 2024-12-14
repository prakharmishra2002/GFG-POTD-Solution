class Solution:
    def search(self, arr, key):
        n = len(arr)
        for i in range(n):
            if arr[i] == key:
                return i
        return -1