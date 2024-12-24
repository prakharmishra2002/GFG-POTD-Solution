class Solution:
    def searchMatrix(self, mat, x):
        n, m = len(mat), len(mat[0])
        l, r = 0, n * m - 1
        while l <= r:
            mid = (l + r) // 2
            val = mat[mid // m][mid % m]
            if val == x:
                return True
            if val < x:
                l = mid + 1
            else:
                r = mid - 1
        return False