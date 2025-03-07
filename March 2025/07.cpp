class Solution {
  public:
    int longestPalinSubseq(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Every single character is a palindrome of length 1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        // Build the dp array
        for (int cl = 2; cl <= n; ++cl) {
            for (int i = 0; i <= n - cl; ++i) {
                int j = i + cl - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
