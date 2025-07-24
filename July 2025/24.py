class Solution:
    def getLastMoment(self, n, left, right):
        # If no ants on either side, result is 0
        return max(
            max(left) if left else 0,
            n - min(right) if right else 0
        )
