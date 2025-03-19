class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;
        if (2 * k >= n) {
            int profit = 0;
            for (int i = 1; i < n; i++)
                profit += max(0, prices[i] - prices[i - 1]);
            return profit;
        }
        vector<int> dp(2 * k + 1, INT_MIN);
        dp[0] = 0;
        for (int price : prices)
            for (int j = 1; j <= 2 * k; j++)
                dp[j] = j % 2 ? max(dp[j], dp[j - 1] - price) : max(dp[j], dp[j - 1] + price);
        return dp[2 * k];
    }
};


2)
class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        for (int i = 1; i <= k; i++) {
            int maxDiff = -prices[0];
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
                maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
            }
        }
        return dp[k][n - 1];
    }
};

3)
class Solution {
  public:
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& prices, int i, int t, bool holding) {
        if (i == prices.size() || t == 0) return 0;
        if (dp[i][t][holding] != -1) return dp[i][t][holding];
        int skip = solve(prices, i + 1, t, holding);
        if (holding)
            return dp[i][t][holding] = max(skip, prices[i] + solve(prices, i + 1, t - 1, false));
        else
            return dp[i][t][holding] = max(skip, -prices[i] + solve(prices, i + 1, t, true));
    }

    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        dp.assign(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return solve(prices, 0, k, false);
    }
};
