class Solution:
    def longestCommonSum(self, a1, a2):
        n = len(a1)
        diff_arr = [a1[i] - a2[i] for i in range(n)]  # Compute the difference array

        prefix_sum = 0
        index_map = {}  # Stores first occurrence of each prefix_sum
        max_length = 0

        for i in range(n):
            prefix_sum += diff_arr[i]

            if prefix_sum == 0:
                max_length = i + 1  # Whole subarray from start matches
            
            if prefix_sum in index_map:
                max_length = max(max_length, i - index_map[prefix_sum])
            else:
                index_map[prefix_sum] = i  # Store first occurrence
        
        return max_length
