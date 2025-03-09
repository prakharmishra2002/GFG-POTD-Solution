class Solution:
    def countPS(self, s):
        n, res = len(s), 0
        for i in range(n):
            l, r = i, i
            while l >= 0 and r < n and s[l] == s[r]: res += 1; l -= 1; r += 1
            l, r = i, i + 1
            while l >= 0 and r < n and s[l] == s[r]: res += 1; l -= 1; r += 1
        return res - n
