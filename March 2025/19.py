class Solution:
    def maxProfit(self, prices, k):
        n = len(prices)
        if n == 0 or k == 0:
            return 0
        if 2 * k >= n:
            return sum(max(0, prices[i] - prices[i - 1]) for i in range(1, n))
        dp = [-float('inf')] * (2 * k + 1)
        dp[0] = 0
        for price in prices:
            for j in range(1, 2 * k + 1):
                dp[j] = max(dp[j], dp[j - 1] - price) if j % 2 else max(dp[j], dp[j - 1] + price)
        return dp[2 * k]
