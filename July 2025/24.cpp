class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLeft = 0, maxRight = 0;

        // Ants moving left fall off at their current positions
        for (int pos : left) {
            maxLeft = max(maxLeft, pos);
        }

        // Ants moving right fall off at n - pos
        for (int pos : right) {
            maxRight = max(maxRight, n - pos);
        }

        // Return the maximum time when the last ant falls
        return max(maxLeft, maxRight);
    }
};
