# User function Template for python3
import heapq

class Solution:
    def minCost(self, houses):
        def manhattan_distance(p1, p2):
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])
        
        n = len(houses)
        if n == 0:
            return 0
        
        min_heap = [(0, 0)]  # (cost, house_index)
        visited = set()
        total_cost = 0
        
        while len(visited) < n:
            cost, house_index = heapq.heappop(min_heap)
            if house_index in visited:
                continue
            visited.add(house_index)
            total_cost += cost
            
            for i in range(n):
                if i not in visited:
                    heapq.heappush(min_heap, (manhattan_distance(houses[house_index], houses[i]), i))
        
        return total_cost
