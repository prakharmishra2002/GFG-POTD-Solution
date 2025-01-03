class Solution:
    def subarrayXor(self, arr, k):
        res, prefXOR = 0, 0
        count = {0: 1}
        for val in arr:
            prefXOR ^= val
            res += count.get(prefXOR ^ k, 0)
            count[prefXOR] = count.get(prefXOR, 0) + 1
        return res