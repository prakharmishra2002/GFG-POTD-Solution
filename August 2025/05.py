class Solution:
    def isPalinSent(self, s):
        # Filter out non-alphanumeric characters and convert to lowercase
        cleaned = ''.join(ch.lower() for ch in s if ch.isalnum())
        # Check if the cleaned string is the same forwards and backwards
        return cleaned == cleaned[::-1]
