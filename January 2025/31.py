class Solution:

    def solveSudoku(self, mat):
        def solve(b, r, c, box, i, j):
            if i == 9:
                return True
            if j == 9:
                return solve(b, r, c, box, i + 1, 0)
            if b[i][j] != 0:
                return solve(b, r, c, box, i, j + 1)
            for num in range(1, 10):
                m = 1 << num
                idx = i // 3 * 3 + j // 3
                if (r[i] & m) != 0 or (c[j] & m) != 0 or (box[idx] & m) != 0:
                    continue
                b[i][j] = num
                r[i] |= m
                c[j] |= m
                box[idx] |= m
                if solve(b, r, c, box, i, j + 1):
                    return True
                b[i][j] = 0
                r[i] &= ~m
                c[j] &= ~m
                box[idx] &= ~m
            return False

        r = [0] * 9
        c = [0] * 9
        box = [0] * 9
        for i in range(9):
            for j in range(9):
                if mat[i][j] != 0:
                    m = 1 << mat[i][j]
                    idx = i // 3 * 3 + j // 3
                    r[i] |= m
                    c[j] |= m
                    box[idx] |= m
        solve(mat, r, c, box, 0, 0)
