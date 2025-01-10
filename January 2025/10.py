from collections import defaultdict

class Solution:
    def countDistinct(self, arr, k):
        n = len(arr)
        if k > n:
            return []
        
        # Dictionary to store the count of elements in the current window
        window_count = defaultdict(int)
        distinct_counts = []
        
        # Initialize the first window
        for i in range(k):
            window_count[arr[i]] += 1
        
        distinct_counts.append(len(window_count))
        
        # Slide the window over the array
        for i in range(k, n):
            # Remove the element going out of the window
            if window_count[arr[i - k]] == 1:
                del window_count[arr[i - k]]
            else:
                window_count[arr[i - k]] -= 1
            
            # Add the new element coming into the window
            window_count[arr[i]] += 1
            
            # Append the count of distinct elements in the current window
            distinct_counts.append(len(window_count))
        
        return distinct_counts
