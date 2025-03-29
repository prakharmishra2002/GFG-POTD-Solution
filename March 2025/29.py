class Solution:
    def jobSequencing(self, deadline, profit):
        # Combine jobs with their deadlines and profits
        jobs = list(zip(deadline, profit))
        
        # Sort jobs in decreasing order of profit
        jobs.sort(key=lambda x: x[1], reverse=True)
        
        # Find the maximum deadline
        max_deadline = max(deadline)
        
        # Create an array to track free time slots
        parent = list(range(max_deadline + 1))
        
        def findParent(x):
            # A function to find the parent slot using path compression
            if parent[x] == x:
                return x
            parent[x] = findParent(parent[x])
            return parent[x]

        max_profit = 0
        jobs_done = 0

        # Iterate through the sorted jobs
        for d, p in jobs:
            # Find the latest available slot before or at the deadline
            available_slot = findParent(min(d, max_deadline))
            if available_slot > 0:  # A slot is available
                parent[available_slot] = findParent(available_slot - 1)  # Mark the slot as taken
                max_profit += p
                jobs_done += 1

        return [jobs_done, max_profit]
