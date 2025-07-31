#include <vector>
#include <map>
using namespace std;

class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // Build a difference map
        map<int, int> diff;
        for (auto& interval : intervals) {
            int start = interval[0];
            int end   = interval[1];
            diff[start]++;        // +1 at the interval’s start
            diff[end + 1]--;      // -1 right after the interval’s end
        }

        // Sweep through the map to compute prefix sums
        int currentOverlap = 0;
        int maxPowerful    = -1;
        for (auto& [point, delta] : diff) {
            currentOverlap += delta;
            if (currentOverlap >= k) {
                maxPowerful = point;
            }
        }

        return maxPowerful;
    }
};
