class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<int> dp(W + 1);
        for (int i = 0; i < wt.size(); i++)
            for (int j = W; j >= wt[i]; j--)
                dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
        return dp[W];
    }
};

2)
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1));

        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= W; j++) 
                dp[i][j] = (wt[i - 1] <= j) 
                          ? max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]) 
                          : dp[i - 1][j];

        return dp[n][W];
    }
};

3)
class Solution {
  public:
    vector<vector<int>> dp;
    int solve(vector<int> &val, vector<int> &wt, int i, int W) {
        if (i < 0 || W == 0) return 0;
        if (dp[i][W] != -1) return dp[i][W];

        int pick = (wt[i] <= W) ? val[i] + solve(val, wt, i - 1, W - wt[i]) : 0;
        int notPick = solve(val, wt, i - 1, W);

        return dp[i][W] = max(pick, notPick);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        dp.assign(wt.size(), vector<int>(W + 1, -1));
        return solve(val, wt, wt.size() - 1, W);
    }
};
