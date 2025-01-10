#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> result;
        if (k > n) return result;

        unordered_map<int, int> window_count;

        // Initialize the first window
        for (int i = 0; i < k; ++i) {
            window_count[arr[i]]++;
        }
        result.push_back(window_count.size());

        // Slide the window over the array
        for (int i = k; i < n; ++i) {
            // Remove the element going out of the window
            if (window_count[arr[i - k]] == 1) {
                window_count.erase(arr[i - k]);
            } else {
                window_count[arr[i - k]]--;
            }

            // Add the new element coming into the window
            window_count[arr[i]]++;

            // Append the count of distinct elements in the current window
            result.push_back(window_count.size());
        }

        return result;
    }
};
