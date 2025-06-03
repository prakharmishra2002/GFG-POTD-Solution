from collections import defaultdict

class Solution:
    def countSubstr(self, s, k):
        def atMostK(s, k):
            count = defaultdict(int)
            left = 0
            total = 0
            
            for right in range(len(s)):
                count[s[right]] += 1
                
                while len(count) > k:
                    count[s[left]] -= 1
                    if count[s[left]] == 0:
                        del count[s[left]]
                    left += 1
                
                total += right - left + 1
            
            return total
        
        return atMostK(s, k) - atMostK(s, k - 1)
