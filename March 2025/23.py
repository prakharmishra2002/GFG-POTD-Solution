class Solution:
    def countWays(self, s: str) -> int:
        if s[0] == '0': return 0
        prev2, prev1 = 1, 1
        for i in range(1, len(s)):
            curr = prev1 if s[i] != '0' else 0
            if s[i - 1] != '0' and int(s[i - 1:i + 1]) <= 26:
                curr += prev2
            prev2, prev1 = prev1, curr
        return prev1
