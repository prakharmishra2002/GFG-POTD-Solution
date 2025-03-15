class Solution {
  public:
    int minCoins(vector<int>& coins, int sum) {
        vector<int> dp(sum + 1, INT_MAX);
        dp[0] = 0;
        for (int c : coins)
            for (int j = c; j <= sum; j++)
                if (dp[j - c] != INT_MAX)
                    dp[j] = min(dp[j], dp[j - c] + 1);
        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};
