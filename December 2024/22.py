class Solution:
    def matSearch(self, mat, x):
        r, c = 0, len(mat[0]) - 1
        while r < len(mat) and c >= 0:
            if mat[r][c] == x: return True
            elif mat[r][c] > x: c -= 1
            else: r += 1
        return False