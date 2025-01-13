class Solution:
    def maxWater(self, arr):
        left, right = 0, len(arr) - 1
        max_water = 0
        
        while left < right:
            width = right - left
            height = min(arr[left], arr[right])
            current_water = width * height
            max_water = max(max_water, current_water)
            
            if arr[left] < arr[right]:
                left += 1
            else:
                right -= 1
        
        return max_water
