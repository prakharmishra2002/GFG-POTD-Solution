class Solution:
    def countStrings(self, s): 
        freq = {}
        for char in s:
            freq[char] = freq.get(char, 0) + 1

        n = len(s)
        total_swaps = n * (n - 1) // 2  # All possible index swaps

        # Count duplicate swaps where the swapped characters are identical
        duplicate_count = sum((val * (val - 1)) // 2 for val in freq.values())

        return total_swaps - duplicate_count + (1 if duplicate_count > 0 else 0)
