class Node:
    def __init__(self, x):
        self.data = x
        self.next = None

class Solution:
    def mergeKLists(self, arr):
        import heapq

        # Create a min-heap to store the nodes
        heap = []
        
        # Add the first node of each list to the heap
        for l in arr:
            if l:
                heapq.heappush(heap, (l.data, l))
        
        # Create a dummy node to form the merged list
        dummy = Node(0)
        current = dummy
        
        # Extract the smallest element from the heap and add it to the merged list
        while heap:
            val, node = heapq.heappop(heap)
            current.next = Node(val)
            current = current.next
            if node.next:
                heapq.heappush(heap, (node.next.data, node.next))
        
        # Return the head of the merged list
        return dummy.next
