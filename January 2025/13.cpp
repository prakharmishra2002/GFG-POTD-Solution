#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;
        int max_water = 0;

        while (left < right) {
            int width = right - left;
            int height = min(arr[left], arr[right]);
            int current_water = width * height;
            max_water = max(max_water, current_water);

            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};
