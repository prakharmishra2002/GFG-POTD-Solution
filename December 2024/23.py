class Solution:
    def searchRowMatrix(self, mat, x):
        for row in mat:
            if x in row: 
                return True
        return False