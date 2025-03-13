class Solution:
    def knapsack(self, W, val, wt):
        dp = [0] * (W + 1)
        for i in range(len(wt)):
            for j in range(W, wt[i] - 1, -1):
                dp[j] = max(dp[j], val[i] + dp[j - wt[i]])
        return dp[W]
