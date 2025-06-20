from collections import Counter
import heapq

class Solution:
    def validgroup(self, arr, k):
        if len(arr) % k != 0:
            return False

        freq = Counter(arr)
        min_heap = list(freq.keys())
        heapq.heapify(min_heap)

        while min_heap:
            first = min_heap[0]
            for i in range(first, first + k):
                if freq[i] == 0:
                    return False
                freq[i] -= 1
                if freq[i] == 0 and i != min_heap[0]:
                    # Remove i from heap when it's no longer needed
                    min_heap.remove(i)
                    heapq.heapify(min_heap)
            # Remove the current min if its count reaches 0
            if freq[first] == 0:
                heapq.heappop(min_heap)

        return True
