class Solution {
public:
    // Function to find a solved Sudoku.
    void solveSudoku(std::vector<std::vector<int>>& mat) {
        std::vector<int> r(9, 0), c(9, 0), box(9, 0);
        
        // Initialize the state of rows, columns, and boxes
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (mat[i][j] != 0) {
                    int m = 1 << mat[i][j], idx = i / 3 * 3 + j / 3;
                    r[i] |= m; 
                    c[j] |= m; 
                    box[idx] |= m;
                }
            }
        }

        solve(mat, r, c, box, 0, 0);
    }

private:
    bool solve(std::vector<std::vector<int>>& b, std::vector<int>& r, std::vector<int>& c, std::vector<int>& box, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return solve(b, r, c, box, i + 1, 0);
        if (b[i][j] != 0) return solve(b, r, c, box, i, j + 1);

        for (int num = 1; num <= 9; ++num) {
            int m = 1 << num;
            int idx = i / 3 * 3 + j / 3;
            if ((r[i] & m) || (c[j] & m) || (box[idx] & m)) continue;
            b[i][j] = num;
            r[i] |= m;
            c[j] |= m;
            box[idx] |= m;
            if (solve(b, r, c, box, i, j + 1)) return true;
            b[i][j] = 0;
            r[i] &= ~m;
            c[j] &= ~m;
            box[idx] &= ~m;
        }

        return false;
    }
};
