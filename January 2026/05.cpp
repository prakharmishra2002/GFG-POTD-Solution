#include <vector>
#include <algorithm>  // for std::max
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        if (n < k || k <= 0) return 0;
        
        // Sum of first window
        long long windowSum = 0;
        for (int i = 0; i < k; ++i) {
            windowSum += arr[i];
        }
        
        long long maxSum = windowSum;
        
        // Slide the window
        for (int i = k; i < n; ++i) {
            windowSum += arr[i] - arr[i - k];
            maxSum = max(maxSum, windowSum);
        }
        
        return maxSum;
    }
};
