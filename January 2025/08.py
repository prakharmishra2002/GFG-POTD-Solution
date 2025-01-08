class Solution:
    # Function to count the number of possible triangles.
    def countTriangles(self, arr):
        # Sort the array.
        arr.sort()
        n = len(arr)
        count = 0
        
        # Iterate through the array using three pointers.
        for i in range(n - 2):
            k = i + 2
            for j in range(i + 1, n - 1):
                while k < n and arr[i] + arr[j] > arr[k]:
                    k += 1
                # Count the number of possible triangles with arr[i] and arr[j]
                if k > j:
                    count += k - j - 1
        
        return count
