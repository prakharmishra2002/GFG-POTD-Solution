class Solution:
    def longestStringChain(self, words):
        # Sort the words based on their length
        words.sort(key=len)
        
        # Dictionary to keep track of the longest chain ending with each word
        dp = {}
        
        max_chain_length = 1
        
        for word in words:
            dp[word] = 1  # Every word can be a chain of at least length 1 (itself)
            
            # Check all possible predecessor words by removing one character
            for i in range(len(word)):
                predecessor = word[:i] + word[i+1:]
                if predecessor in dp:
                    dp[word] = max(dp[word], dp[predecessor] + 1)
            
            # Update the max chain length
            max_chain_length = max(max_chain_length, dp[word])
        
        return max_chain_length
