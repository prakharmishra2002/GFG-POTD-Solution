class Solution:
    def aggressiveCows(self, stalls, k):
        stalls.sort()
        low, high = 1, stalls[-1] - stalls[0]

        while low <= high:
            mid = (low + high) // 2
            count, last_placed = 1, stalls[0]
            for i in range(1, len(stalls)):
                if stalls[i] - last_placed >= mid:
                    count += 1
                    last_placed = stalls[i]
            if count >= k:
                low = mid + 1
            else:
                high = mid - 1
        return high