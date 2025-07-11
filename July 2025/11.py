class Solution:
    def countConsec(self, n: int) -> int:
        # dp[i][0] = count of strings of length i ending in '0' without consecutive 1's
        # dp[i][1] = count of strings of length i ending in '1' without consecutive 1's
        dp = [[0, 0] for _ in range(n + 1)]
        dp[1][0] = 1  # "0"
        dp[1][1] = 1  # "1"

        for i in range(2, n + 1):
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1]  # can add '0' after either '0' or '1'
            dp[i][1] = dp[i - 1][0]  # can add '1' only after '0' (to avoid consecutive 1's)

        total = 2 ** n  # total binary strings of length n
        valid = dp[n][0] + dp[n][1]  # strings without consecutive 1's
        return total - valid  # strings with at least one pair of consecutive 1's
