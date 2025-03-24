class Solution {
public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len < n; len++) {
            for (int i = 1, j = len; j < n; i++, j++) {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                    dp[i][j] = min(dp[i][j], arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j]);
            }
        }
        return dp[1][n - 1];
    }
};

2)

class Solution {
public:
    int dp[1005][1005];

    int solve(vector<int>& arr, int i, int j) {
        if (i == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            int cost = arr[i-1] * arr[k] * arr[j] + solve(arr, i, k) + solve(arr, k+1, j);
            ans = min(ans, cost);
        }
        return dp[i][j] = ans;
    }

    int matrixMultiplication(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));
        return solve(arr, 1, arr.size() - 1);
    }
};
