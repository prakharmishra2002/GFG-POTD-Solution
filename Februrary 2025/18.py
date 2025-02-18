class Solution:
    def kClosest(self, p: list[list[int]], k: int) -> list[list[int]]:
        return sorted(p, key=lambda a: a[0]**2 + a[1]**2)[:k]
