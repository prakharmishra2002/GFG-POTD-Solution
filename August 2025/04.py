class Solution:
    def maxRectSum(self, mat):
        def kadane(arr):
            max_sum = float('-inf')
            current_sum = 0
            for val in arr:
                current_sum = max(val, current_sum + val)
                max_sum = max(max_sum, current_sum)
            return max_sum

        if not mat or not mat[0]:
            return 0

        n = len(mat)
        m = len(mat[0])
        max_sum = float('-inf')

        for left in range(m):
            temp = [0] * n
            for right in range(left, m):
                for i in range(n):
                    temp[i] += mat[i][right]
                max_sum = max(max_sum, kadane(temp))

        return max_sum
