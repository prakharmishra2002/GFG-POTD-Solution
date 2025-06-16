#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
  public:
    // Helper to compute total cost for converting all heights to 'target'
    long long getCost(const vector<int>& heights, const vector<int>& cost, int target) {
        long long total = 0;
        for (int i = 0; i < heights.size(); ++i) {
            total += 1LL * abs(heights[i] - target) * cost[i];
        }
        return total;
    }

    int minCost(vector<int>& heights, vector<int>& cost) {
        int left = *min_element(heights.begin(), heights.end());
        int right = *max_element(heights.begin(), heights.end());
        long long answer = LLONG_MAX;

        // Ternary search over the height range
        while (right - left > 2) {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;

            long long cost1 = getCost(heights, cost, mid1);
            long long cost2 = getCost(heights, cost, mid2);

            if (cost1 < cost2)
                right = mid2;
            else
                left = mid1;
        }

        // Final check within narrow range
        for (int i = left; i <= right; ++i) {
            answer = min(answer, getCost(heights, cost, i));
        }

        return (int)answer;
    }
};
