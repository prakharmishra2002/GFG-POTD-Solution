class TrieNode:
    def __init__(self):
        self.children = {}

class Solution:
    def maxXor(self, arr):
        # Helper function to insert a number into the Trie
        def insert(num):
            node = trie
            for i in range(31, -1, -1):  # Iterate over 32 bits (assuming 32-bit integers)
                bit = (num >> i) & 1
                if bit not in node.children:
                    node.children[bit] = TrieNode()
                node = node.children[bit]

        # Helper function to find maximum XOR for a number
        def findMaxXor(num):
            node = trie
            maxXor = 0
            for i in range(31, -1, -1):
                bit = (num >> i) & 1
                oppositeBit = 1 - bit
                if oppositeBit in node.children:  # Try to take the opposite bit if possible
                    maxXor = (maxXor << 1) | 1
                    node = node.children[oppositeBit]
                else:  # Otherwise, take the current bit
                    maxXor = maxXor << 1
                    node = node.children[bit]
            return maxXor

        # Build Trie and calculate maximum XOR
        trie = TrieNode()
        maxResult = 0
        insert(arr[0])  # Insert the first number into the Trie
        for i in range(1, len(arr)):
            maxResult = max(maxResult, findMaxXor(arr[i]))
            insert(arr[i])
        
        return maxResult
