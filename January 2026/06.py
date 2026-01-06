class Solution:
    def maxSubarrayXOR(self, arr, k):
        n = len(arr)
        if n == 0 or k == 0 or k > n:
            return 0  # though constraints guarantee valid input
        
        # Compute prefix XOR array
        # prefix[i] = XOR of elements from index 0 to i-1
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] ^ arr[i]
        
        # Now we need to find maximum prefix[j] ^ prefix[i] where j - i == k
        # i.e., for every possible ending index j (from k-1 to n-1),
        # compute prefix[j+1] ^ prefix[j+1 - k] and keep the maximum
        ans = 0
        for j in range(k - 1, n):
            current_xor = prefix[j + 1] ^ prefix[j + 1 - k]
            ans = max(ans, current_xor)
        
        return ans
