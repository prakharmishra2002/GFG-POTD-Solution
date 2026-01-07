from collections import defaultdict

class Solution:
    def countDistinct(self, arr, k):
        n = len(arr)
        if k > n:
            return []

        freq = defaultdict(int)
        result = []

        # Initialize the first window
        for i in range(k):
            freq[arr[i]] += 1
        result.append(len(freq))

        # Slide the window
        for i in range(k, n):
            # Remove the element going out of the window
            outgoing = arr[i - k]
            freq[outgoing] -= 1
            if freq[outgoing] == 0:
                del freq[outgoing]

            # Add the new element coming into the window
            incoming = arr[i]
            freq[incoming] += 1

            # Append the count of distinct elements
            result.append(len(freq))

        return result
