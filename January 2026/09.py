from collections import defaultdict

class Solution:
    def countAtMostK(self, arr, k):
        n = len(arr)
        left = 0
        count = 0
        freq = defaultdict(int)

        for right in range(n):
            freq[arr[right]] += 1

            while len(freq) > k:
                freq[arr[left]] -= 1
                if freq[arr[left]] == 0:
                    del freq[arr[left]]
                left += 1

            # All subarrays ending at 'right' and starting from 'left' to 'right' are valid
            count += right - left + 1

        return count
