class Solution:
    def setMatrixZeroes(self, mat):
        n, m, col0 = len(mat), len(mat[0]), 1
        for i in range(n):
            if mat[i][0] == 0: col0 = 0
            for j in range(1, m):
                if mat[i][j] == 0:
                    mat[i][0] = mat[0][j] = 0
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, 0, -1):
                if mat[i][0] == 0 or mat[0][j] == 0:
                    mat[i][j] = 0
            if col0 == 0: mat[i][0] = 0