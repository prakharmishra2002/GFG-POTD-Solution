class Solution: 
    def countPairs(self, arr, target): 
        # Dictionary to store the frequency of elements
        freq = {}
        count = 0
        
        for num in arr:
            # Calculate the complement that would form the target sum
            complement = target - num
            
            # If the complement exists in the dictionary, add its frequency to the count
            if complement in freq:
                count += freq[complement]
            
            # Update the frequency of the current number
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1
        
        return count
