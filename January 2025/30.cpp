#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        vector<vector<int>> board(n, vector<int>(n, 0));
        solveNQueens(n, board, 0, res);
        return res;
    }

private:
    bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
        for (int i = 0; i < col; i++)
            if (board[row][i] == 1)
                return false;

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1)
                return false;

        for (int i = row, j = col; i < n && j >= 0; i++, j--)
            if (board[i][j] == 1)
                return false;

        return true;
    }

    bool solveNQueens(int n, vector<vector<int>>& board, int col, vector<vector<int>>& res) {
        if (col >= n) {
            vector<int> solution;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 1) {
                        solution.push_back(j + 1);
                    }
                }
            }
            res.push_back(solution);
            return true;
        }

        bool res_flag = false;
        for (int i = 0; i < n; i++) {
            if (isSafe(board, i, col, n)) {
                board[i][col] = 1;
                res_flag = solveNQueens(n, board, col + 1, res) || res_flag;
                board[i][col] = 0;
            }
        }
        return res_flag;
    }
};
