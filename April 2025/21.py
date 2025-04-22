class Solution:
    def missingNum(self, a):
        x, n = 0, len(a)
        for i in range(n): x ^= a[i] ^ (i + 1)
        return x ^ (n + 1)


2)
class Solution:
    def missingNum(self, arr):
        x = 0
        for i, v in enumerate(arr):
            x ^= v ^ (i + 1)
        return x ^ (len(arr) + 1)
