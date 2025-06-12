class Solution:
    def printKClosest(self, arr, k, x):
        # Create a list to store the differences and corresponding elements
        diff = []
        
        # Iterate through the array and calculate the difference
        for num in arr:
            if num != x:
                diff.append((abs(num - x), -num))  # Using -num to ensure higher values come first in case of a tie
        
        # Sort the list based on the absolute difference and then by element value in descending order
        diff.sort()
        
        # Extract the k closest elements
        result = [-y[1] for y in diff[:k]]
        
        return result
