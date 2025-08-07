class Solution:
    def minDifference(self, arr):
        def time_to_seconds(t):
            h, m, s = map(int, t.split(":"))
            return h * 3600 + m * 60 + s

        # Convert all times to seconds
        seconds = sorted(time_to_seconds(t) for t in arr)

        # Initialize min_diff with a large number
        min_diff = float('inf')

        # Compare adjacent times
        for i in range(1, len(seconds)):
            diff = seconds[i] - seconds[i - 1]
            min_diff = min(min_diff, diff)

        # Check wrap-around difference between last and first time
        wrap_diff = 86400 - seconds[-1] + seconds[0]  # 86400 seconds in a day
        min_diff = min(min_diff, wrap_diff)

        return min_diff
