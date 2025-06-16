#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
  public:
    long long getCost(const vector<int>& heights, const vector<int>& cost, int target) {
        long long totalCost = 0;
        for (int i = 0; i < heights.size(); ++i) {
            totalCost += 1LL * abs(heights[i] - target) * cost[i];
        }
        return totalCost;
    }

    int minCost(vector<int>& heights, vector<int>& cost) {
        int left = *min_element(heights.begin(), heights.end());
        int right = *max_element(heights.begin(), heights.end());
        long long answer = LLONG_MAX;

        // Ternary Search
        while (right - left > 2) {
            int m1 = left + (right - left) / 3;
            int m2 = right - (right - left) / 3;

            long long cost1 = getCost(heights, cost, m1);
            long long cost2 = getCost(heights, cost, m2);

            if (cost1 < cost2)
                right = m2;
            else
                left = m1;
        }

        for (int i = left; i <= right; ++i) {
            answer = min(answer, getCost(heights, cost, i));
        }

        return (int)answer;
    }
};
