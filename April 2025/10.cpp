#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        auto manhattanDistance = [](const vector<int>& p1, const vector<int>& p2) {
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
        };

        int n = houses.size();
        if (n == 0) return 0;

        // Min-heap: {cost, house_index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<bool> visited(n, false);
        int totalCost = 0;

        minHeap.push({0, 0}); // Start with the first house

        while (visited.end() != find(visited.begin(), visited.end(), false)) { // While there are unvisited houses
            auto [cost, houseIndex] = minHeap.top();
            minHeap.pop();

            if (visited[houseIndex]) continue;
            visited[houseIndex] = true;
            totalCost += cost;

            for (int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    int dist = manhattanDistance(houses[houseIndex], houses[i]);
                    minHeap.push({dist, i});
                }
            }
        }

        return totalCost;
    }
};
