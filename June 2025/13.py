import math

class Solution:
    def kokoEat(self, arr, k):
        # Function to check if Koko can eat all bananas at a given rate (speed)
        def canEatAll(speed):
            hours = 0
            for bananas in arr:
                hours += math.ceil(bananas / speed)  # Compute required hours
            return hours <= k
        
        # Binary search for minimum eating speed
        left, right = 1, max(arr)
        while left < right:
            mid = (left + right) // 2
            if canEatAll(mid):  # If possible to eat within k hours
                right = mid  # Try a smaller speed
            else:
                left = mid + 1  # Increase speed
        
        return left  # Minimum eating speed
