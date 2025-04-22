class Solution:
    def findUnique(self, arr):
        r = 0
        for x in arr: r ^= x
        return r
