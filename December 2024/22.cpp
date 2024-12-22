class Solution {
public:
    bool matSearch(vector<vector<int>>& mat, int x) {
        int r = 0, c = mat[0].size() - 1;
        while (r < mat.size() && c >= 0) {
            if (mat[r][c] == x) return true;
            else if (mat[r][c] > x) c--;
            else r++;
        }
        return false;
    }
};