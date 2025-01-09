class Solution:
    def subarraySum(self, arr, target):
        current_sum = 0
        start = 0
        for end in range(len(arr)):
            current_sum += arr[end]
            while current_sum > target and start <= end:
                current_sum -= arr[start]
                start += 1
            if current_sum == target:
                return [start + 1, end + 1]
        return [-1]
