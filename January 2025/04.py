class Solution:
    def countTriplets(self, arr, target):
        n, res = len(arr), 0
        for i in range(n - 2):
            left, right = i + 1, n - 1
            while left < right:
                sum_triplet = arr[i] + arr[left] + arr[right]
                if sum_triplet < target:
                    left += 1
                elif sum_triplet > target:
                    right -= 1
                else:
                    if arr[left] == arr[right]:
                        count = right - left + 1
                        res += count * (count - 1) // 2
                        break
                    cnt1, cnt2 = 1, 1
                    while left + 1 < right and arr[left] == arr[left + 1]:
                        left += 1
                        cnt1 += 1
                    while right - 1 > left and arr[right] == arr[right - 1]:
                        right -= 1
                        cnt2 += 1
                    res += cnt1 * cnt2
                    left += 1
                    right -= 1
        return res