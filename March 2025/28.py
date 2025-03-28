
class Solution:
    def activitySelection(self, start, finish):
        ans, finishtime = 0, -1
        for s, f in sorted(zip(start, finish), key=lambda x: x[1]):
            if s > finishtime: finishtime = f; ans += 1
        return ans
