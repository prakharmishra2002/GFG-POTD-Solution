class Solution {
  public:
    int kadane(const vector<int>& nums) {
        int max_current = nums[0];
        int max_global = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            max_current = max(nums[i], max_current + nums[i]);
            max_global = max(max_global, max_current);
        }
        return max_global;
    }

    int maxCircularSum(vector<int> &arr) {
        int total_sum = 0;
        vector<int> inverted(arr.size());
        
        for (size_t i = 0; i < arr.size(); ++i) {
            total_sum += arr[i];
            inverted[i] = -arr[i];
        }

        int max_kadane = kadane(arr);         // Case 1: normal max subarray sum
        int min_kadane = kadane(inverted);    // Case 2: minimum subarray sum (via inversion)

        // If all elements are negative, circular case is invalid
        if (total_sum + min_kadane == 0) {
            return max_kadane;
        }

        return max(max_kadane, total_sum + min_kadane); // Case 2: wrap-around sum
    }
};
