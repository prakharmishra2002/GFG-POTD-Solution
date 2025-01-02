class Solution:
    def countSubarrays(self, arr, k):
        prefix_sum_count = {0: 1}
        sum_, count = 0, 0

        for num in arr:
            sum_ += num
            count += prefix_sum_count.get(sum_ - k, 0)
            prefix_sum_count[sum_] = prefix_sum_count.get(sum_, 0) + 1

        return count