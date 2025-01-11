class Solution:
    def longestUniqueSubstr(self, s):
        n = len(s)
        if n == 0:
            return 0
        
        max_len = 0
        start = 0
        char_index = {}
        
        for end in range(n):
            if s[end] in char_index:
                start = max(start, char_index[s[end]] + 1)
            char_index[s[end]] = end
            max_len = max(max_len, end - start + 1)
        
        return max_len
