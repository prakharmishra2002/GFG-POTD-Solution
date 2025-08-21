class Solution:
    def maxMinDiff(self, arr, k):
        # Sort the array to make difference calculations easier
        arr.sort()

        # Helper function to check if we can select k elements
        # with at least 'min_diff' between any two
        def is_possible(min_diff):
            count = 1
            last_selected = arr[0]

            for i in range(1, len(arr)):
                if arr[i] - last_selected >= min_diff:
                    count += 1
                    last_selected = arr[i]
                    if count == k:
                        return True
            return False

        # Binary search for the maximum minimum difference
        low = 0
        high = arr[-1] - arr[0]
        result = 0

        while low <= high:
            mid = (low + high) // 2
            if is_possible(mid):
                result = mid
                low = mid + 1
            else:
                high = mid - 1

        return result
