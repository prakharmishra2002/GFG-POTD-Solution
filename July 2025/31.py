class Solution:
    def powerfulInteger(self, intervals, k):
        # Build sweep events: +1 at start, -1 at end+1
        events = []
        for start, end in intervals:
            events.append((start, 1))
            events.append((end + 1, -1))
        
        # Sort by coordinate
        events.sort()
        
        ans = -1
        count = 0           # current overlapping intervals
        prev = None         # previous event coordinate
        i = 0
        n = len(events)
        
        # Sweep through events
        while i < n:
            x = events[i][0]
            
            # If in a powerful segment [prev, x-1], update ans
            if prev is not None and prev < x and count >= k:
                ans = max(ans, x - 1)
            
            # Apply all events at x
            delta = 0
            while i < n and events[i][0] == x:
                delta += events[i][1]
                i += 1
            count += delta
            prev = x
        
        return ans
