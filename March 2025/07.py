class Solution:
    
    def longestPalinSubseq(self, s):
        n = len(s)
        dp = [[0] * n for _ in range(n)]

        # Every single character is a palindrome of length 1
        for i in range(n):
            dp[i][i] = 1

        # Build the dp array
        for cl in range(2, n + 1):
            for i in range(n - cl + 1):
                j = i + cl - 1
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j])

        return dp[0][n - 1]
