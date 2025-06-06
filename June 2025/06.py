class Solution:
    def search(self, pat, txt):
        # Base variables
        d = 256  # Number of characters in the input alphabet
        q = 101  # A prime number for hashing
        m = len(pat)
        n = len(txt)
        p = 0  # Hash value for pattern
        t = 0  # Hash value for text
        h = 1
        result = []

        # Compute the value of h as "pow(d, m-1) % q"
        for i in range(m-1):
            h = (h * d) % q

        # Compute the hash values for pattern and first window of text
        for i in range(m):
            p = (d * p + ord(pat[i])) % q
            t = (d * t + ord(txt[i])) % q

        # Slide the pattern over text one by one
        for i in range(n - m + 1):
            # Check if the hash values match
            if p == t:
                # If hash matches, check character by character
                if txt[i:i+m] == pat:
                    result.append(i + 1)  # 1-based indexing

            # Compute hash for the next window
            if i < n - m:
                t = (d * (t - ord(txt[i]) * h) + ord(txt[i + m])) % q

                # Convert negative values to positive
                if t < 0:
                    t += q
        
        return result
