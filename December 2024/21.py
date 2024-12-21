class Solution:
    def rotateby90(self, mat): 
        n = len(mat)
        for i in range(n):
            for j in range(i, n):
                mat[i][j], mat[j][i] = mat[j][i], mat[i][j]
        for j in range(n):
            i, k = 0, n - 1
            while i < k:
                mat[i][j], mat[k][j] = mat[k][j], mat[i][j]
                i += 1
                k -= 1