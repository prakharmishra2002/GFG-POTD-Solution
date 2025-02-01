class Solution:
    def __init__(self):
        self.rowDir = [0, 0, -1, 1] # Left, Right, Up, Down
        self.colDir = [-1, 1, 0, 0]

    def isWordExist(self, mat, word):
        n = len(mat)
        m = len(mat[0])

        # Iterate through the matrix to find the first character
        for i in range(n):
            for j in range(m):
                if mat[i][j] == word[0]:
                    if self.dfs(mat, i, j, word, 0, [[False]*m for _ in range(n)]):
                        return True
        return False

    def dfs(self, mat, row, col, word, index, visited):
        if index == len(word):
            return True

        # Boundary conditions and character match check
        if row < 0 or col < 0 or row >= len(mat) or col >= len(mat[0]) or visited[row][col] or mat[row][col] != word[index]:
            return False

        # Mark as visited
        visited[row][col] = True

        # Explore all 4 directions
        for d in range(4):
            newRow = row + self.rowDir[d]
            newCol = col + self.colDir[d]

            if self.dfs(mat, newRow, newCol, word, index + 1, visited):
                return True

        # Backtrack
        visited[row][col] = False
        return False
