class Solution:
    def nQueen(self, n):
        def solveNQueens(n):
            def isSafe(board, row, col):
                # Check upper diagonal on left side
                for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
                    if board[i][j] == 1:
                        return False
                # Check left side
                for i in range(col):
                    if board[row][i] == 1:
                        return False
                # Check lower diagonal on left side
                for i, j in zip(range(row, n, 1), range(col, -1, -1)):
                    if board[i][j] == 1:
                        return False
                return True

            def solveUtil(board, col):
                if col >= n:
                    solution = []
                    for i in range(n):
                        solution.append(board[i].index(1) + 1)
                    res.append(solution)
                    return True
                res_flag = False
                for i in range(n):
                    if isSafe(board, i, col):
                        board[i][col] = 1
                        res_flag = solveUtil(board, col + 1) or res_flag
                        board[i][col] = 0
                return res_flag

            res = []
            board = [[0 for _ in range(n)] for _ in range(n)]
            solveUtil(board, 0)
            return res
        
        return solveNQueens(n)
