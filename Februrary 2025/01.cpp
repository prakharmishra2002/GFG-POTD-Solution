class Solution {
  public:
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0]) {
                    if (dfs(mat, i, j, word, 0, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

  private:
    int rowDir[4] = {0, 0, -1, 1}; // Left, Right, Up, Down
    int colDir[4] = {-1, 1, 0, 0};

    bool dfs(vector<vector<char>>& mat, int row, int col, string& word, int index, vector<vector<bool>>& visited) {
        if (index == word.size()) {
            return true;
        }

        if (row < 0 || col < 0 || row >= mat.size() || col >= mat[0].size() || visited[row][col] || mat[row][col] != word[index]) {
            return false;
        }

        visited[row][col] = true;

        for (int d = 0; d < 4; d++) {
            int newRow = row + rowDir[d];
            int newCol = col + colDir[d];

            if (dfs(mat, newRow, newCol, word, index + 1, visited)) {
                return true;
            }
        }

        visited[row][col] = false;
        return false;
    }
};
