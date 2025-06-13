#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Helper function to check if Koko can eat all bananas within k hours at given speed
        auto canEatAll = [&](int speed) {
            int hours = 0;
            for (int bananas : arr) {
                hours += (bananas + speed - 1) / speed;  // Equivalent to ceil(bananas / speed)
            }
            return hours <= k;
        };

        // Binary search for minimum eating speed
        int left = 1, right = *max_element(arr.begin(), arr.end());
        while (left < right) {
            int mid = (left + right) / 2;
            if (canEatAll(mid)) {
                right = mid;  // Try a smaller speed
            } else {
                left = mid + 1;  // Increase speed
            }
        }

        return left;  // Minimum eating speed
    }
};
