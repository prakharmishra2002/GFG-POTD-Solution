class Solution:
    def longestKSubstr(self, s, k):
        n = len(s)
        if k == 0 or n == 0:
            return -1
        
        char_freq = {}
        max_len = -1
        left = 0
        
        for right in range(n):
            # Add the current character to the frequency map
            char_freq[s[right]] = char_freq.get(s[right], 0) + 1

            # Shrink window if number of distinct characters exceeds k
            while len(char_freq) > k:
                char_freq[s[left]] -= 1
                if char_freq[s[left]] == 0:
                    del char_freq[s[left]]
                left += 1
            
            # Check if we have exactly k distinct characters
            if len(char_freq) == k:
                max_len = max(max_len, right - left + 1)
        
        return max_len
