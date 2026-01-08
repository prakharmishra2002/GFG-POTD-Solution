from collections import defaultdict

class Solution:
    def countSubarrays(self, arr, k):
        count = 0
        odd_count = 0
        freq = defaultdict(int)
        freq[0] = 1  # Base case: zero odd numbers seen

        for num in arr:
            if num % 2 != 0:
                odd_count += 1

            # If we've seen (odd_count - k) before, it means there's a subarray ending here with k odds
            count += freq[odd_count - k]
            freq[odd_count] += 1

        return count
