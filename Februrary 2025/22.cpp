class Solution {
  public:
    int maxLength(string& s) {
        vector<int> dp(s.size() + 1, 0);
        int max_len = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                } else if (i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '(') {
                    dp[i] = (i - dp[i-1] >= 2 ? dp[i - dp[i-1] - 2] : 0) + dp[i-1] + 2;
                }
                max_len = max(max_len, dp[i]);
            }
        }
        return max_len;
    }
};
