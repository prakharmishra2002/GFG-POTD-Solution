import heapq

class Solution:
    def __init__(self):
        self.max_heap = []  # Max heap for the lower half
        self.min_heap = []  # Min heap for the upper half
    
    def addNum(self, num: int) -> None:
        # Add to max heap (invert sign to simulate a max heap using Python's min heap)
        heapq.heappush(self.max_heap, -num)
        
        # Balance the heaps
        if self.max_heap and self.min_heap and (-self.max_heap[0] > self.min_heap[0]):
            val = -heapq.heappop(self.max_heap)
            heapq.heappush(self.min_heap, val)
        
        # Maintain size property
        if len(self.max_heap) > len(self.min_heap) + 1:
            val = -heapq.heappop(self.max_heap)
            heapq.heappush(self.min_heap, val)
        
        if len(self.min_heap) > len(self.max_heap):
            val = heapq.heappop(self.min_heap)
            heapq.heappush(self.max_heap, -val)
    
    def findMedian(self) -> float:
        if len(self.max_heap) > len(self.min_heap):
            return -self.max_heap[0]
        return (-self.max_heap[0] + self.min_heap[0]) / 2

    def getMedian(self, arr):
        result = []
        for num in arr:
            self.addNum(num)
            result.append(self.findMedian())
        return result
