class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size(), l = 0, r = n * m - 1;
        while (l <= r) {
            int mid = (l + r) / 2, val = mat[mid / m][mid % m];
            if (val == x) return true;
            val < x ? l = mid + 1 : r = mid - 1;
        }
        return false;
    }
};