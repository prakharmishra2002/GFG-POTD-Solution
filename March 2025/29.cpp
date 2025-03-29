class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size(); // Number of jobs
        vector<pair<int, int>> jobs;
        
        // Combine deadlines and profits into a vector of pairs
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }
        
        // Sort jobs in decreasing order of profit
        sort(jobs.rbegin(), jobs.rend());
        
        // Find the maximum deadline
        int maxDeadline = 0;
        for (int d : deadline) {
            maxDeadline = max(maxDeadline, d);
        }
        
        // Parent array for union-find
        vector<int> parent(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++) {
            parent[i] = i;
        }
        
        // Function to find the parent of a slot (using path compression)
        function<int(int)> findParent = [&](int x) -> int {
            if (parent[x] == x) return x;
            return parent[x] = findParent(parent[x]);
        };
        
        int maxProfit = 0, jobsDone = 0;

        // Iterate through the jobs
        for (auto &job : jobs) {
            int p = job.first;
            int d = job.second;

            // Find the latest available slot
            int availableSlot = findParent(d);
            if (availableSlot > 0) {
                parent[availableSlot] = findParent(availableSlot - 1); // Mark the slot as taken
                maxProfit += p;
                jobsDone++;
            }
        }

        return {jobsDone, maxProfit};
    }
};
