class Solution:
    def lcs(self, s1, s2):
        m, n = len(s1), len(s2)
        dp = [0] * (n + 1)
        for i in range(m):
            prev = 0
            for j in range(n):
                temp = dp[j + 1]
                dp[j + 1] = prev + 1 if s1[i] == s2[j] else max(dp[j + 1], dp[j])
                prev = temp
        return dp[n]
