#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int current_sum = 0;
        int start = 0;
        for (int end = 0; end < arr.size(); ++end) {
            current_sum += arr[end];
            while (current_sum > target && start <= end) {
                current_sum -= arr[start];
                start++;
            }
            if (current_sum == target) {
                return {start + 1, end + 1}; // 1-based index
            }
        }
        return {-1};
    }
};
