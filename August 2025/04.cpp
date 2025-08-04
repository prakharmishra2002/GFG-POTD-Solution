class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxSum = INT_MIN;

        // Traverse all column pairs
        for (int left = 0; left < m; ++left) {
            vector<int> temp(n, 0);
            for (int right = left; right < m; ++right) {
                // Collapse columns from left to right into temp
                for (int i = 0; i < n; ++i) {
                    temp[i] += mat[i][right];
                }

                // Apply Kadane’s algorithm on temp
                int currentSum = temp[0], bestSum = temp[0];
                for (int i = 1; i < n; ++i) {
                    currentSum = max(temp[i], currentSum + temp[i]);
                    bestSum = max(bestSum, currentSum);
                }
                maxSum = max(maxSum, bestSum);
            }
        }
        return maxSum;
    }
};
