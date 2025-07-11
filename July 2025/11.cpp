class Solution {
  public:
    int countConsec(int n) {
        if (n == 0) return 0;

        // dp[i][0] = count of strings of length i ending in '0' without consecutive 1's
        // dp[i][1] = count of strings of length i ending in '1' without consecutive 1's
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[1][0] = 1; // "0"
        dp[1][1] = 1; // "1"

        for (int i = 2; i <= n; ++i) {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1]; // add '0' after either '0' or '1'
            dp[i][1] = dp[i - 1][0];                // add '1' only after '0'
        }

        int total = 1 << n; // Total binary strings of length n (2^n)
        int valid = dp[n][0] + dp[n][1]; // Valid ones without consecutive 1's

        return total - valid; // Those that have at least one pair of consecutive '1's
    }
};
