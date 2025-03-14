class Solution:
    def count(self, coins, sum):
        dp = [0] * (sum + 1)
        dp[0] = 1
        for coin in coins:
            for j in range(coin, sum + 1):
                dp[j] += dp[j - coin]
        return dp[sum]
