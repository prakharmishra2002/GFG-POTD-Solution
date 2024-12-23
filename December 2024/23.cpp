class Solution {
public:
    bool searchRowMatrix(vector<vector<int>>& mat, int x) {
        for (auto& row : mat) {
            if (binary_search(row.begin(), row.end(), x)) return true;
        }
        return false;
    }
};