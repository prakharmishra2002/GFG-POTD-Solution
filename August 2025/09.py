class Solution:
    def getLongestPrefix(self, s: str) -> int:
        n = len(s)
        if n <= 1:
            return -1

        # Build Z-array: z[i] = longest substring starting at i
        # that matches a prefix of s
        z = [0] * n
        l = r = 0
        for i in range(1, n):
            if i <= r:
                # mirror within [l..r]
                z[i] = min(r - i + 1, z[i - l])
            # extend match past r
            while i + z[i] < n and s[z[i]] == s[i + z[i]]:
                z[i] += 1
            if i + z[i] - 1 > r:
                l, r = i, i + z[i] - 1

        # Scan from longest possible proper prefix downwards
        for length in range(n - 1, 0, -1):
            # if z[length] covers the rest of the string,
            # repeating the prefix of this length will match s
            if z[length] >= n - length:
                return length

        return -1
