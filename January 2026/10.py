from collections import defaultdict

class Solution:
    def countSubstr(self, s, k):
        def atMostK(s, k):
            count = 0
            left = 0
            freq = defaultdict(int)

            for right in range(len(s)):
                freq[s[right]] += 1

                while len(freq) > k:
                    freq[s[left]] -= 1
                    if freq[s[left]] == 0:
                        del freq[s[left]]
                    left += 1

                count += right - left + 1
            return count

        # Substrings with exactly k distinct = atMostK(k) - atMostK(k - 1)
        return atMostK(s, k) - atMostK(s, k - 1)
