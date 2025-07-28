class Solution {
public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size(), max = 0, res = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) sum += mat[i][j];
            max = sum > max ? sum : max;
        }
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) sum += mat[i][j];
            max = sum > max ? sum : max;
        }
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) sum += mat[i][j];
            res += max - sum;
        }
        return res;
    }
};
