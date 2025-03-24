class Solution:
    def matrixMultiplication(self, arr):
        n, dp = len(arr), [[0] * len(arr) for _ in range(len(arr))]

        for l in range(2, n):
            for i in range(1, n - l + 1):
                j, dp[i][i + l - 1] = i + l - 1, float('inf')
                for k in range(i, j):
                    dp[i][j] = min(dp[i][j], arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j])
        
        return dp[1][n - 1]
