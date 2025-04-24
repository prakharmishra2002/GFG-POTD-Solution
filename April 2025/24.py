class Solution:
    def getSingle(self, arr):
        ones = twos = 0
        for num in arr:
            ones = (ones ^ num) & ~twos
            twos = (twos ^ num) & ~ones
        return ones
