class Solution:
    def countPairs(self, arr, target):
        freq_map, count = {}, 0
        for num in arr:
            count += freq_map.get(target - num, 0)
            freq_map[num] = freq_map.get(num, 0) + 1
        return count