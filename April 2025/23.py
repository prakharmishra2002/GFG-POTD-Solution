class Solution:
    def singleNum(self, arr):
        xor_sum = 0
        for num in arr:
            xor_sum ^= num
        
        # Find rightmost set bit
        rightmost_set_bit = xor_sum & -xor_sum
        
        num1 = num2 = 0
        for num in arr:
            if num & rightmost_set_bit:
                num1 ^= num
            else:
                num2 ^= num
        
        return sorted([num1, num2])
